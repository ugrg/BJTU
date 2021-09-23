#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  string org,target;
  cin >> n >> org >> target;
  int l = 0;
  for(int i=0; i< org.size(); i++){
    if(org[i]!=target[i]) l++;
  }
  cout << (l > (n + 1)/2 ? n + 1 - l : l) << endl;
}