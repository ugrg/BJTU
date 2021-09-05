#include <iostream>
#include <vector>

using namespace std;

int f(vector<int> &A, int p, int q) {
  int step = A[q] - A[p], l = 2;
  p = q++;
  for(; q < A.size(); q++) {
    if(A[q] - A[p] == step) {
      p = q;
      l++;
    }
  }
  return l;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n,0);
  for(int i=0; i < n; i++) {
    cin >> A[i];
  }
  int l = 2;
  for(int p = 0; p < n; p++) {
    for(int q = p + 1; q < n; q++) {
      int lr = f(A, p, q);
      l = l > lr ? l : lr;
    }
  }
  int del = l == 2 ? -1 : n - l;
  cout << del << endl;
}