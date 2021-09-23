#include <iostream>
#include <string>
#include <list>
using namespace std;

class St {
  public:
    string name;
    int y,s,w;
    int sum;
    St() {
      cin >> name >> y >> s >> w;
      sum = y + s + w;
    }
    bool operator>(St &st) {
      if(sum > st.sum) return true;
      if(sum < st.sum) return false;
      if(s > st.s) return true;
      if(s < st.s) return false;
      if(w > st.w) return true;
      if(w < st.w) return false;
      return name < st.name;
    }
    string print(int X, int Y){
      char st[100];
      sprintf(st,"Case %d: %d %d\n%s %d %d %d %d\n",X, Y, sum, name.c_str(), sum, y, s, w);
      return string(st);
    }
};

bool comp(St &a, St &b){
  return a > b;
}

int main() {
  int S,Q,l;
  cin >> S >> Q;
  list<St> sts(S);
  sts.sort(comp);
  string out="";
  for(int i=0; i < Q; i++){
    cin >> l;
    list<St>::iterator p = sts.begin();
    int k = l;
    while(k > 1) {p++; k--;}
    out += (*p).print(i+1,l);
  }
  cout << out << endl;
}