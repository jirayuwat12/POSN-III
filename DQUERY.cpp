#include <unordered_set> //faster
#include <set> // slower
#include <iostream>
#include <vector>
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
using namespace std;

int main(){
  // freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\DQUERY.in","r",stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,temp,start,stop;
  vector<int> vi;
  set<int> s;
  cin>>n;
  FOR(i,0,n){
    cin>>temp;
    vi.pb(temp);
  }
  cin>>n;
  vector<int> ans(n);
  FOR(i,0,n){
    s.clear();
    cin>>start>>stop;
    FOR(j,start-1,stop){
      s.insert(vi[j]);
    }
    ans[i] = s.size();
  }
  FOR(i,0,n){
    cout<<ans[i]<<'\n';
  }

}
