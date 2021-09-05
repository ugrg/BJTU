#include <iostream>
//#include <ctime>
#include <vector>
using namespace std;

#define Index vector<vector<int>>

int find(Index &index, int dep, int min, int p) {
  vector<int> &q = index[dep];    
  if(dep + 1 == index.size()) {
    return q.size() - p;
  } else {
    int sum = 0, p1 = 0, m;
    vector<int> &nextQ = index[dep + 1];
    while(p != q.size()){
      m = q[p] + 1;
      while(nextQ[p1] < m && p1 < nextQ.size()) p1++;
      sum += find(index, dep + 1, m, p1);
      p++;
    }
    return sum;
  }
}

int main() {
  int n, m;
  string S, W;
  cin >> n >> m;
  cin >> S >> W;
  // clock_t t1 = clock();
  Index index(W.length());
  vector<int> cur(W.length(), 0);
  for(int pw = 0; pw < m; pw++) {
    char w0 = W.at(pw);
    int ps = S.find(w0);
    vector<int> &sn = index[pw];
    while(ps != string::npos) {
      sn.push_back(ps);
      ps = S.find(w0, ps + 1);
    }
  }  
  cout << find(index, 0, index[0][0], 0) << endl;
  // cout << "time=" << clock() - t1 << endl;
}