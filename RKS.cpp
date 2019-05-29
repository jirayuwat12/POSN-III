#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <queue>
#include <algorithm>
#include <unordered_set>
#define pb push_back
#define FOR(i,s,n) for(it i=s;i<n;i++)
typedef int64_t it;
using namespace std;
/*
SPOJ-RKS RK sorting
*/
bool Compare(const tuple<it,int,int> &a,const tuple<it,int,int> &b){
  return (get<1>(a) > get<1>(b)) || (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b));
}

int main(){
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\RKS.in","r",stdin);
  it n,c;
  it temp;
  cin>>n>>c;
  unordered_map<it,int> mf;
  unordered_map<it,int> mi;
  vector<tuple<it,int,int> > vti;
  FOR(i,0,n){
    cin>>temp;
    if(mf[temp] == 0) mi[temp] = i;
    mf[temp]++;
  }
  FOR(i,0,c+1){
    if(mf[i] != 0){
      vti.pb({i,mf[i],mi[i]});
    }
  }
  sort(vti.begin(),vti.end(),Compare);
  for(auto j : vti){
    for(int i=0;i<get<1>(j);i++) cout<<get<0>(j)<<' ';
  }
}
