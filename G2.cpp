#include <iostream>
#include <ctime>
using namespace std;

int subFind(string S,string W) {
	char w0 = W.at(0);
	int sum = 0, wl = W.length();
	int p = S.find(w0);
	while(p != string::npos) {
		if(wl > 1) {
			sum += subFind(S.substr(p+1),W.substr(1));
		} else {
			sum ++;
		}
		p = S.find(w0, p+1);
	}
	return sum;
} 

int main() {
	int n,m;
	string S,W;
	cin >> n >> m;
	cin >> S >> W;

	clock_t t1 = clock();
	cout << subFind(S, W) << endl;
	clock_t t2 = clock();
	cout << t2 - t1 << endl;
}



