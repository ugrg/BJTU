#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Point {
  int y;
  int x;
  int w;
};

typedef Point* PPoint;
typedef list<PPoint> PL;
typedef list<PPoint>::iterator PLT;
typedef list<PLT>::iterator PLTT;

bool comp(const PPoint &a, const PPoint &b) {
  return a->y==b->y ? a->x < b->x : a->y < b->y;
}

void createIndex(PL &task,list<PLT> &index) {
  task.sort(comp);
  int y = -1;
  PLT p = task.begin();
  index.push_back(p);
  while(p!=task.end()) {
    if((*p)->y != y) {
      y = (*p)->y;
      index.push_back(p);
      index.push_back(p++);
    } else {
      p++;
    }
  }
  index.push_back(task.end());
}

int statistics(list<PLT> &index, int left, int top, int right, int bottom) {
  int sum = 0;
  for(PLTT yp = index.begin(); yp != index.end(); yp++) {
    PLT xs = *yp++;
    PLT xe = *yp;
    Point &q = **xs;
    if(q.y < top) continue;
    if(q.y > bottom) break;
    for(; xs!=xe; xs++) {
      Point &p = **xs;
      if(p.x < left) continue;
      if(p.x > right) break;
      sum += p.w;
    }
  }
  return sum;
}

void print(list<PLT> &index) {
  for(PLTT yp = index.begin(); yp != index.end(); yp++) {
    PLT xs = *yp++;
    PLT xe = *yp;
    for(; xs!=xe; xs++) {
      Point &p = **xs;
      printf("y=%d,x=%d,w=%d\n",p.y,p.x,p.w);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n, x, y, w;
  PL task;
  cin >> n;
  for(int i = 0; i < n; i++) {
    PPoint t = new Point();
    cin >> t->x >> t->y >> t->w;
    task.push_back(t);
  }
  list<PLT> index;
  createIndex(task,index);
  print(index);
  int q,left,top,right,bottom;
  cin >> q;
  char temp[20];
  string result;
  for(int i=0; i<q; i++) {
    cin >> left >> top >> right >> bottom;
    sprintf(temp,"%d\n",statistics(index, left, top, right, bottom));
    result+=temp;
  }
  cout << result;
  for(PLT p = task.begin();p!=task.end();p++) delete *p;
}