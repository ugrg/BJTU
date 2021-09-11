#include <iostream>

using namespace std;

void init(int data[], int N) {
  int x = (N - 1) / 2, x1;
  int y = 0, y1;
  int len = N * N;
  for(int i = 1; i <= len; i++) {
    data[y * N + x] = i;
    y1 = (y - 1 + N) % N;
    x1 = (x + 1) % N;
    if(data[y1 * N + x1]) {
      x1 = x;
      y1 = (y + 1) % N;
    }
    x = x1;
    y = y1;
  }
}
void print(int data[],int N){
  for(int y=0; y<N; y++){
    for(int x=0; x<N; x++){
      cout << data[y * N + x] << ",\t";
    }
    cout << endl;
  }
}

int main() {
  int N,M,x,y;
  cin >> N >> M;
  int data[N * N]= {0};
  init(data,N);
  print(data,N);
  int out[M] = {0};
  for(int i=0; i < M; i++) {
    cin >> x >> y;
    out[i]= data[(x - 1) * N + y - 1];
  }
  for(int i=0; i<M; i++) {
    cout << out[i] << endl;
  }
}