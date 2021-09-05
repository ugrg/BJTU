#include <iostream>
#include <vector>
#include <ctime>

#define int64 long long

using namespace std;

const int64 mod = 114514;

// 蒙哥马利算法
int64 Montgomery(int64 base, int64 exp) {
  int64 res = 1;
  while( exp ) {
    if(exp & 1) res = (res * base) % mod;
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}


int main() {
  int64 n,c;
  cin >> n >> c;
  vector<int64> a(n, 0);
  for(int i=0; i <= n; i++) {
    cin >> a[i];
  }
  int64 sum = 0;
  for(int i = 0; i <= n; i++) {
    sum = (sum + a[i] * Montgomery(c,i)) % mod;
  }
  cout << sum << endl;
}