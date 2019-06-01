#include <vector>
#include <unordered_map>
#include <iostream>
#define pb push_back
using namespace std;

unordered_map<int,bool> maked;
unordered_map<int,vector<int> > LV_need;
unordered_map<int,vector<int> > T_need;
int i,n,k,t,j,ans;
int result(unordered_map<int,vector<int> > LV_need,unordered_map<int,bool> maked,int ks){
  for(int ia=0;ia<ks;ia++){
    bool ck = false;
    for(auto jf : LV_need[ia]){
      if(!maked[jf]) ck = true;
    }
    if(ck) return (ia==0) ? -1:ia;
  }
}
int set_make(int jh){
  for(auto ij : T_need[jh]){
    if(!maked[ij]) {
      set_make(ij);
    }
  }maked[jh] = true,t--;
  if(t==0) {j=k;
  return 100;}
}
int main(){
  cin>>n>>k>>t;
  for(i=0;i<n;i++){
    int lv,run,need;
    cin>>lv>>run;
    LV_need[lv].pb(i);
    for(int j=0;j<run;j++){
      cin>>need;
      T_need[i].pb(need);
    }
  }
  j=0;ans=-1;
  for(i=0;i<k && j!= k;i++){
    for(auto j : LV_need[i]){
      if(!maked[j]) n =set_make(j);
      if(n ==100) break;
    }ans = i;
  }
  cout<<ans;

}
