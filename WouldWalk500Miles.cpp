#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define N1 2019201913
#define N2 2019201949
#define MOD 2019201997
using namespace std;
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define FORR(i,s,n) for(int i=s;i>n;i--)
typedef long long ll;

bool merg(int *p,int *r,int p_u,int p_v){
  if(r[p_u] < r[p_v]) p[p_v] = p_u;
  else p[p_u] = p_v;
  if(r[p_u] == r[p_v]) r[p_u] ++;
  return 1;
}

int find(int *p,int x){
  if(p[x] != x) find(p,p[x]);
  else return x;
}
int Compare(const tuple<int,int,ll> &a,const tuple<int,int,ll> &b){
  return( get<2>(a) >get<2>(b));
}
int Mst(vector<tuple<int,int,ll> > g,int V,int k){
  int *p = new int [V+1];
  int *r = new int [V+1];
  FOR(i,0,V+1) p[i] = i,r[i] = 0;
  vector<ll> dist;
  for(auto i : g ){
    int u = get<0>(i);
    int v = get<1>(i);
    int p_u = find (p,u);
    int p_v = find (p,v);
    if(p_u != p_v){
      dist.pb(get<2>(i));
      cout<<get<2>(i)<<'='<<get<0>(i)<<'-'<<get<1>(i)<<endl;
      merg(p,r,p_u,p_v);
    }
  }
  sort(dist.begin(),dist.end());
  // for(auto i : dist) cout<<"i = "<<i<<endl;
  cout<<dist[k-2];
  return 0;
}

ll findDist(ll a,ll b){
  if ( a > b ) swap(a,b);
  return ( (N1*a) + (N2 * b) ) % MOD;
}

int main(){
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\WouldWalk500Miles.in","r",stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  ll ll_temp;
  cin>>n>>k;
  vector<tuple<int,int,ll> > g;
  FOR(i,1,n+1){
    FOR(j,i+1,n+1){
      ll_temp = findDist(i,j);
      // cout<<"ll temp = "<<ll_temp<<'\n';
      g.pb({i,j,ll_temp});
      g.pb({j,i,ll_temp});
    }
  }
  Mst(g,n+1,k);

}
