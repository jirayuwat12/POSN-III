#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define FORR(i,s,n) for(int i=s;i>n;i--)
typedef long long ll;

map<int,int> field ;
int ss(int j,vector<int> g[]){
  if(field[j] != 0) return 0;
  map<int,bool> used;
  for(auto i : g[j]) used[field[i]] = true;
  FOR(i,1,5) if(!used[i]) {field[j] = i;break;}
  sort(g[j].begin(),g[j].end());
  for(auto i:g[j]) ss(i,g);

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\TGRB.in","r",stdin);
  int n,m;
  cin>>n>>m;
  vector<int> g[n+1];
  int u,v;
  FOR(i,0,m){
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }
  ss(1,g);
  for(auto i:field) cout<<i.second;
}
/*
1-4 2 5
2-4 5 1
3-4
4-1 2 3
5-2 1
*/
