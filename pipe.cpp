#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <math.h>
using namespace std;
#include <algorithm>
#define pb push_back
int find(int *p,int x){
  if(p[x] != x)find(p,p[x]);
  else return x;
}
void merg(int pu,int pv,int *p,int *r){
  pu = find(p,pu);
  pv = find(p,pv);
  if(r[pu] < r[pv]) p[pv] = pu;
  else p[pu] = pv;
  if(r[pu] == r[pv]) r[pv] ++;
}
int mst(vector<tuple <int,int,int> > g,int v,int k){
  sort(g.begin(),g.end());
  for(auto i :g) cout<<get<2>(i)<<' ';
  unordered_map<int,bool> connected;
  for(auto i:g){
    if(connected[get<0>(i)])
  }
  // while(!dist.empty()) cout<<dist.top()<<' ',dist.pop();
  // for(int i=0;i<K;i++){
  //   sum -= dist.top();
  //   dist.pop();
  // }
  // return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\pipe.in","r",stdin);
  int i=0,n,k;
  cin>>n>>k;
  int db[n][2];
  while(i<n){
    cin>>db[i][0]>>db[i][1];
    i++;
  }
  vector<tuple<int,int,int>> g;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int dist = abs(db[i][0] - db[j][0]) + abs(db[i][1] - db[j][1]);
      // cout<<dist<<' ';
      g.pb({i,j,dist});
      g.pb({j,i,dist});
    }
  }
  // sort(g.begin(),g.end());
  // for(auto i:g){
  //   cout<<get<0>(i)<<'-'<<get<1>(i)<<'='<<get<2>(i)<<endl;
  // }
  int ans =mst(g,n,k);
  // cout<<ans;
}
