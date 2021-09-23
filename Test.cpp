#include <iostream>
#include <ctime>
#include <list>
#include <string>
using namespace std;
#define LIT list<int>::iterator
int N;

char F[10];
inline void write( int x ) {
  int tmp = x;
  int cnt = 0 ;
  while( tmp > 0 ) {
    F[cnt++] = tmp % 10 + '0' ;
    tmp /= 10 ;
  }
  while(cnt>0) putchar(F[--cnt]);
  putchar('\n');
}

inline int szw() {
  int LX[N]= {0};
  for (int i = 0 ; i < N ; i++) LX[i] = i;
  clock_t t2 = clock();
  for (int i = 0 ; i < N ; i++) write(LX[i]);
  clock_t t3 = clock();
  return t3-t2;
}

inline int liw() {
  list<int> l;
  for (int i = 0 ; i < N ; i++) l.push_back(i);
  clock_t t2 = clock();
  for (LIT it=l.begin(); it!=l.end(); it++) write(*it);
  clock_t t3 = clock();
  return t3-t2;
}

inline int szc() {
  int LX[N]= {0};
  for (int i = 0 ; i < N ; i++) LX[i] = i;
  clock_t t2 = clock();
  for (int i = 0 ; i < N ; i++) cout << LX[i] << endl;
  clock_t t3 = clock();
  return t3-t2;
}

inline int lic() {
  list<int> l;
  for (int i = 0 ; i < N ; i++) l.push_back(i);
  clock_t t2 = clock();
  for (LIT it=l.begin(); it!=l.end(); it++) cout << (*it) << endl;
  clock_t t3 = clock();
  return t3-t2;
}

inline int szs() {
  int LX[N]= {0};
  for (int i = 0 ; i < N ; i++) LX[i] = i;
  string s;
  s.reserve(N*10);
  clock_t t2 = clock();
  for (int i = 0 ; i < N ; i++) {
    sprintf(F,"%d\n",LX[i]);
    s+=F;
  }
  cout << s;
  clock_t t3 = clock();
  return t3-t2;
}

inline int lis() {
  list<int> l;
  string s;
  s.reserve(N*10);
  for (int i = 0 ; i < N ; i++) l.push_back(i);
  clock_t t2 = clock();
  for (LIT it=l.begin(); it!=l.end(); it++) {
    sprintf(F,"%d\n",*it);
    s+=F;
  };
  cout << s;
  clock_t t3 = clock();
  return t3-t2;
}

int main() {
//  ios::sync_with_stdio(false); 
//  cin.tie(0);
//  cout.tie(0);
//  cin>>N;
//  int t1 = szw(),t2=liw(),t3=szc(),t4=lic();
//  int t5 = szs(),t6=lis();
//  cout<<"[] cout="<<t1<<endl;
//  cout<<"list cout="<<t2<<endl;
//  cout<<"[] cout="<<t3<<endl;
//  cout<<"list cout="<<t4<<endl;
//  cout<<"[] cout="<<t5<<endl;
//  cout<<"list cout="<<t6<<endl;
  string s1 = "ABC", s2 = "abc";
  cout << (s1 > s2) << endl;
}
