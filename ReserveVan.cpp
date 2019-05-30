#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define FORR(i,s,n) for(int i=s;i>n;i--)
typedef long long ll;

int set_min(auto i){
  int min = 20001;
  for(auto j : i){
    if(min>j.second) min =j.second;
  }
  return min;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\ReserveVan.in","r",stdin);
  int temp,n,k,minn=0;
  cin>>n>>k;
  vector<pair<int,int>> sche(k);
  vector<int> ans;
  FOR(i,0,k) sche[i] = {i,0};
  FOR(i,0,n){
    cin>>temp;
    vector<pair<int,int>> :: iterator it;
    it = sche.begin();
    while(it != sche.end()){
      if(it->second == minn) {
        ans.pb(it->first);
        it->second += temp;
        minn = set_min(sche);
        break;
      }
      it++;
    }
  }
  for(auto i : ans) cout<<i+1<<endl;
}
