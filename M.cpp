#include <iostream>
#include <list>
#include <string>
using namespace std;

class Task {
  public:
    int x, y, w;
    int id;
    Task() {
      cin >> x >> y >> w;
      id = y << 12 | x;
    }
    int inWork(int &x1, int &y1, int &x2, int &y2) {
      if(x>=x1 && x <= x2 && y >= y1 && y <= y2) return w;
      return 0;
    }
};

list<Task*> task;

#define LTT list<Task*>::iterator
#define LTI list<int>::iterator

int sum(int &x1, int &y1, int &x2, int &y2) {
  int sum = 0;
  for(LTT p = task.begin(); p!=task.end(); p++) {
    sum += (*p)->inWork(x1,y1,x2,y2);
  };
  return sum;
}

int main() {
  int n, q, x1, y1, x2, y2;
  for(cin >> n; n > 0; n--) {
    task.push_back(new Task());
  }
  char temp[20];
  string out="";
  for(cin >> q; q > 0; q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    sprintf(temp, "%d\n", sum(x1,y1,x2,y2));    
    out+=temp;
  }
  cout << out;  
  for(LTT p = task.begin(); p!=task.end(); p++) delete *p;
}