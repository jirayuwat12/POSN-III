#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

#define pb push_back
#define FOR(i,s,n) for(auto i=s;i<n;i++)
#define FORR(i,s,n) for(auto i=s;i>n;i--)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef int64_t intt;
int d[6];
void F(){
  int t=d[0];d[0]=d[3];d[3]=d[5];d[5]=d[1];d[1]=t;
}void B(){
  int t=d[0];d[0]=d[1];d[1]=d[5];d[5]=d[3];d[3]=t;
}void L(){
  int t=d[0];d[0]=d[4];d[4]=d[5];d[5]=d[3];d[3]=t;
}void R(){
  int t=d[0];d[0]=d[2];d[2]=d[5];d[5]=d[4];d[4]=t;
}void C(){
  int t=d[1];d[1]=d[4];d[4]=d[3];d[3]=d[2];d[2]=t;
}void D(){
  int t=d[1];d[1]=d[2];d[2]=d[3];d[3]=d[4];d[4]=t;
}void print(){
  FOR(i,0,6) cout<<d[i]<<' ';
}void setD(){
  d[0] = 1;
  d[1] = 2;
  d[2] = 3;
  d[3] = 5;
  d[4] = 4;
  d[5] = 6;
}
int main(){
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\Dice.in" ,"r",stdin);
  int n;
  cin>>n;
  int *ans = new int[n];
  FOR(i,0,n){
    setD();
    string na;
    cin>>na;
    for( auto j : na){
      switch (j) {
        case 'F':F();
          break;
        case 'B':B();
          break;
        case 'L':L();
          break;
        case 'R':R();
          break;
        case 'C':C();
          break;
        case 'D':D();
          break;
      }
      ans[i] = d[1];
    }
  }
  for(int i=0;i<n;i++) cout<<ans[i]<<' ';
}
