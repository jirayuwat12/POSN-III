#include <bits/stdc++.h>

using namespace std;
#define pb push_back
unordered_map<int,vector<int> > T_need;
map<int, vector<int> > LV_need;
map<int,bool>  maked;
int t;
void Make(int k){
  for(auto i: T_need[k]){
    if(!maked[i]){
      Make(i);
    }
  }
  if(t-- >0) maked[k] = true;
}

int main(){
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\technology.in","r",stdin);
  int n,k;
  cin>>n>>k>>t;
  //input
  for(int i=0;i<n;i++){
    int LV,num,temp;
    cin>>LV>>num;
    LV_need[LV].pb(i);
    for(int j=0;j<num;j++){
      cin>>temp;
      T_need[i].pb(temp-1);
    }
  }
  //set
  for(int i=0;i<k;i++){
    for(auto j : LV_need[i]){
      if(!maked[j]) Make(j);
    }
  }
  for(int i=0;i<k;i++){
    for(auto j : LV_need[i]){
      if(!maked[j]) {cout<<--i;i=k;break;}
    }
  }
}
