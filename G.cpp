#include <iostream>
#include <ctime>
#define int64 long long
using namespace std;

int n,m;
string S,W;

int subFind(int s,int w) {
	char w0 = W.at(w);
	int sum = 0, wl = m - w;
	int p = S.find(w0, s);
	while(p != string::npos) {
		if(wl > 1) {
			sum += subFind(p+1, w+1);
		} else {
			sum ++;
		}
		p = S.find(w0, p+1);
	}
	return sum;
}

int main() {
	cin >> n >> m;
	cin >> S >> W; 
	clock_t t1 = clock();
	cout << subFind(0, 0) << endl;
	clock_t t2 = clock();
	cout << t2 - t1 << endl;
}



