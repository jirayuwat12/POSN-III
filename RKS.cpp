#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <algorithm>
#define pb push_back
#define FOR(i,s,n) for(int i=s;i<n;i++)
typedef int64_t it;
using namespace std;
/*
SPOJ-RKS RK sorting
*/
bool Compare(const tuple<it,int,int> &a,const tuple<it,int,int> &b){
  return (get<1>(a) > get<1>(b)) || (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\RKS.in","r",stdin);
  int n;
  it c,temp;
  cin>>n>>c;
  unordered_map<it,int> mf;
  unordered_map<it,int> mi;
  vector<tuple<it,int,int> > vti;
  FOR(i,0,n){
    cin>>temp;
    if(mf[temp]==0) mi[temp] = i;
    mf[temp]++;
  }
  for(auto i : mf){
      vti.pb({i.first,i.second,mi[i.first]});
  }
  sort(vti.begin(),vti.end(),Compare);
  for(auto j : vti){
    // cout<<get<0>(j)<<get<1>(j)<<get<2>(j);
    for(int i=0;i<get<1>(j);i++) cout<<get<0>(j)<<' ';
  }
}
