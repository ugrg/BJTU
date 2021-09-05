#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>

using namespace std;

const double PI = 3.1415926535897932384626433832795;

class Point {
  public:
    double x;
    double y;
    double r;
    Point():r(-1) {
    }

    bool isO() {
      return x == 0 && y == 0;
    }

    bool operator==(Point t) {
      return fabs(t.x - x) <= 0.4 && fabs(t.y - y) <= 0.4;
    }

    Point rotate(double a) {
      Point res;
      double cosa = cos(a);
      double sina = sin(a);
      res.x = x * cosa - y * sina;
      res.y = x * sina + y * cosa;
      return res;
    }

    double angle(Point t) {
      return acos(fabs(x * t.x + y * t.y) / ( R() * t.R() ));
    }

    double R() {
      if(r == -1) {
        r = sqrt(x * x + y * y);
      }
      return r;
    }
};


int main() {

  Point A,B,C,swap;
  Point DEF[]= {Point(),Point(),Point()};
  double r = PI*2, p;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  cin >> DEF[0].x >> DEF[0].y >> DEF[1].x >> DEF[1].y >> DEF[2].x >> DEF[2].y;
  cout << setiosflags(ios::fixed) << setprecision(2);

  while(A.isO()) {
    swap = C;
    C = A;
    A = B;
    B = swap;
  }

  for(int i = 0; i < 3; i++) {
    Point D = DEF[i], E = DEF[(i+1)%3], F = DEF[(i+2)%3];
    p = A.angle(D);
    Point B1 = B.rotate(p);
    Point C1 = C.rotate(p);
    if((B1 == E && C1 == F) || (B1 == F && C1 == E)) {
      r = r > p ? p : r;
    }
  }

  cout << r <<endl;
}