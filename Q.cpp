#include <iostream>
#include <list>

using namespace std;


class Notepad {
    list<char> l,r;
  public:
    Notepad() {

    }
    void insert() {
      char v;
      cin >> v;
      l.push_back(v);
    }
    void del() {
      if(l.size()==0) return;
      l.pop_back();
    }
    void prev() {
      if(l.size()==0) return;
      r.push_front(l.back());
      l.pop_back();
    }
    void next() {
      if(r.size()==0) return;
      l.push_back(r.front());
      r.pop_front();
    }
    string print() {
      string result="";
      for(list<char>::iterator p=l.begin(); p!=l.end(); p++) result += *p;
      result += '|';
      for(list<char>::iterator p=r.begin(); p!=r.end(); p++) result += *p;
      result += '\n';
      return result;
    }
};


int main() {
  int T,n,Case;
  string result="";
  char temp[20];
  cin >> T;
  for(int i=0; i<T; i++) {
    cin >> n;
    Notepad note;
    sprintf(temp,"Case %d:\n",i+1);
    result += temp;
    for(int j=0; j<n; j++) {
      cin >> Case;
      switch(Case) {
        case 1: {
          note.insert();
          break;
        }
        case 2:{
          note.del();
          break;
        }
        case 3:{
          note.prev();
          break;
        }
        case 4:{
          note.next();
          break;
        }
        case 5:{
          result+=note.print();
          break;
        }
      }
    }
  }
  cout << result;
}