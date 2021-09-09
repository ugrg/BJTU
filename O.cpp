#include <iostream>
#include <map>
using namespace std;

map<int,int> M;

int main() {
  int k,n;
  for(int i=0; i < 4; i++) {
    for(cin >> k; k > 0; k--) {
      cin >> n;
      M[n]++;
    }
  }
  int sum=0;
  for(map<int,int>::iterator p=M.begin(); p!= M.end(); p++) {
    sum+= (4 - p->second);
  }
  cout << sum << endl;
}