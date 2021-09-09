#include <iostream>
#include <string>

using namespace std;

void input(int &integer,int &decimal,int &loop) {
  char c;
  int p = 0, in[3]= {0};
  string temp="0";
  while(cin.get(c)) {
    if(c == '.') {
      in[p++] = atoi(temp.c_str());
      temp = "0";
    } else if(c == '(') {
      in[p++] = atoi(temp.c_str());
      temp = "0";
    } else if(c == ')' || c == '\n') {
      in[p] = atoi(temp.c_str());
      break;
    } else {
      temp+=c;
    }
  }
  integer = in[0];
  decimal = in[1];
  loop = in[2];
}

int len(int n) {
  int l = 10;
  while(l < n) {
    l *= 10;
  }
  return l;
}

int gcd(int m, int n) {
  if(m < n) return gcd(n,m);
  return m % n == 0 ? n : gcd(m % n, n);
}

int main() {
  int i, d, l, I = 1, _D, L, M, D;
  input(i, d, l);
  // printf("%d,%d,%d\n",i,d,l);
  _D = len(d);
  L = len(l) - 1;
  M = i * _D * L + d * I * L + l * I *_D;
  D = I * _D * L;
  // printf("_D = %d, L = %d\n", _D, L);
  // printf("M/D = %d/%d = %f\n",M,D,1.0 * M /D);
  int g = gcd(M, D);
  printf("%d/%d\n", M/g, D/g);
}