#include <iostream>
#include <string>
using namespace std;

const string base = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

long long toInt(string &s){
  long long n = 0;
  for(int i=0; i < s.size(); i++){
    n = n * 58 + base.find(s[i]);
  }
  return n;
}

string to58String(long long n){
  string s = "";
  if(n == 0) return "1"; 
  while(n != 0){
    long long m = n % 58;
    n = (n - m) / 58;
    s = base[m] + s;
  }
  return s;
}

int main() {
  string A, B;
  cin >> A >> B;
  cout << to58String(toInt(A) + toInt(B)) << endl;
}