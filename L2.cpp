#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int N, M, x, y, X, Y, p, s, d;
  cin >> N >> M;
  int LX[M]= {0},LY[M]= {0};
  for(int i = 0; i < M; i++) {
    cin >> LY[i] >> LX[i];
  }
  int dn = N * N;
  char f[10];
  string out;
  out.reserve(N*10);
  for(int i = 0; i < M; i++) {
    X = x = --LX[i];
    y = --LY[i];
    p = 2 * x + y + 1 - 2 * N;
    x = (x - p + N) % N;
    y = (y + p + N) % N;
    s = ((3 * dn - N) / 2 + 1 - x * N) % dn;
    d = (X - x + N) % N;
    sprintf(f,"%d\n",s+d);
    out+=f;
  }
  cout<<out;
}