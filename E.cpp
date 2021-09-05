#include <iostream>
#include <list>
#define __int64 long long
using namespace std;

int main() {
  char input;
  string split;
  char lastInput;
  __int64 sum = 0;
  list<__int64> out;
  while(cin.get(input)) {
    if(input==' ') {
      sum+=atol(split.c_str());
      split="";
    } else if(input=='\n') {
      if(lastInput=='\n') {
        break;
      }
      sum += atol(split.c_str());
      split="";
      out.push_back(sum);
      sum=0;
    } else {
      split+=input;
    }
    lastInput = input;
  }
  while(!out.empty()) {
    cout << out.front() << endl;
    out.pop_front();
  }
}