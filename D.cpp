#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
//#include <ctime>

using namespace std;

class Runtime;
list<Runtime*> runQueue;
list<Runtime*> waitQueue;
list<Runtime*> recovery;
map<string, int> heap;

string assig_split = " = ";
string calc_split  = " += ";
string print_split = " ";

class Runtime {
  private:
    int id;
    vector<int> timer;
    vector<string> exec;
    int p = 0;
    int length = 0;
    static Runtime *LOCK;
  public:
    Runtime(int _id, vector<int> &_timer) {
      id = _id + 1;
      timer = _timer;
      string s;
      do {
        getline(cin, s, '\n');
        exec.push_back(s);
      } while(s != "end");
      length = exec.size();
    }
  private:
    void split(string &str, string &separator, string &name, int &v) {
      int i = str.find(separator);
      name = str.substr(0, i);
      string val = str.substr(i + separator.length());
      v = atoi(val.c_str());
      if( v == 0 && val != "0") {
        v = heap[val];
      }
    }

    // v = v1 or const1：为全局变量v赋值，const1表示某个具体的数值（如1、2...），V1为另一个全局变量，若未出现，初始值默认为0，下同
    int assig(string &str) {
      string name;
      int val;
      split(str, assig_split, name, val);
      heap[name] = val;
      return timer[0];
    }
    // v += v1 or const1：算术加运算，v1为另一个全局变量
    int calc(string &str) {
      string name;
      int val;
      split(str, calc_split, name, val);
      heap[name] += val;
      return timer[1];
    }
    // print v：输出变量v的值
    int print(string &str) {
      string name;
      int val;
      split(str, print_split, name, val);
      cout << id << ": " << val << endl;
      return timer[2];
    }
    // lock：加锁
    int lock(int slice) {
      if(LOCK == NULL) {
        LOCK = this;
        return slice - timer[3];
      } else {
        p--;
        runQueue.pop_back();
        waitQueue.push_back(this);
        return 0;
      }
    }
    // unlock：解锁
    int unlock() {
      LOCK = NULL;
      if(waitQueue.size() > 0) {
        Runtime *next = waitQueue.front();
        waitQueue.pop_front();
        runQueue.push_front(next);
      }
      return timer[4];
    }
    // yield：当前程序让出处理器，其剩余时间配额作废
    int yield() {
      return 0;
    }
    // end：程序结束
    int end() {
      runQueue.pop_back();
      recovery.push_back(this);
      return 0;
    }
  public:
    void run(int slice) {
      runQueue.push_back(this);
      while(slice > 0 && p < length) {
        string &str = exec[p++];
//        cout << id << ":"<< p <<"\t" << str << endl;
        if(str.find(" = ") != -1) slice -= assig(str);
        else if(str.find(" += ") != -1) slice -= calc(str);
        else if(str.find("print") == 0) slice -= print(str);
        else if(str == "lock") slice = lock(slice);
        else if(str == "unlock") slice -= unlock();
        else if(str == "yield") slice = yield();
        else if(str == "end") slice = end();
      }
    }
};

Runtime *Runtime::LOCK = NULL;


int main() {
  int N, slice;
  vector<int> timer(7);
  cin >> N >> slice;
  for(int i=0; i<7; i++) cin >> timer[i];
  while(cin.get()!='\n');
  for(int i=0; i<N; i++) {
    Runtime *R = new Runtime(i, timer);
    runQueue.push_back(R);
  }
//  clock_t t1 = clock();
//  cout << "start" << endl;

  while(runQueue.size()) {
    Runtime &r = *runQueue.front();
    runQueue.pop_front();
    r.run(slice);
  }

  while(recovery.size()) {
    delete recovery.front();
    recovery.pop_front();
  }
//  cout << clock() - t1 << endl;
}