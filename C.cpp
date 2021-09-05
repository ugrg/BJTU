#include <iostream>
#include <sstream>
using namespace std;

stringstream createS(int n) {
  stringstream  s;
  for(int p=1; p<=n; p++) {
    s << p;
  }
  return s;
}

int find(string S, string A) {
  int length = S.length();
  int sum = 0, p = 0, f;
  while(1) {
    f = S.find(A,p);
    if(f == string::npos) break;
    p = f + 1;
    sum ++;
  }

  return sum;
}

int main() {
  string S = "";
  string A = "";
  int n = 0;
  int sum = 0;
  cin >> n >> A;
  createS(n) >> S;
  cout << find(S,A) << endl;
}