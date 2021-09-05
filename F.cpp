#include <iostream>
#include <vector>

#define int64 long long

using namespace std;

const int64 mod = 114514;

int main() {
  int64 n, c;
  cin >> n >> c;
  vector<int64> a(n + 1, 0);
  for(int i=0; i <= n; i++) {
    cin >> a[i];
  }
  int64 xi = 1, sum = 0;
  for(int i = 0; i <= n; i++) {
    sum = (sum + a[i] * xi) % mod;
    xi = (xi * c) % mod;
  }
  cout << sum << endl;
}