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

int PickDP(int *db,int n){
  int t[n][n];
  for (int gap = 0; gap < n; ++gap) {
    for (int i = 0, j = gap; j < n; ++i, ++j) {
      int x = (i+2 <= j )? t[i+2][j]:0;
      int y = (i+1 <= j-1)?t[i+1][j-1]:0;
      int z = (i <= j-2)?t[i][j-2]:0;
      t[i][j] = max(db[i] + min(x,y),db[j] + min(y,z));
    }
  }
  FOR(i,0,n){
    FOR(j,0,n){
      cout<<t[i][j]<<' ';
    }cout<<endl;
  }
  return t[0][n-1];
}
int PickRecur(int *db,int h,int r){
  if(h == r) return db[r];
  else if(h+1 ==r) return max(db[h],db[r]);
  else return max(db[h] + min(PickRecur(db,h+2,r),PickRecur(db,h+1,r-1)),db[r] + min(PickRecur(db,h+1,r-1),PickRecur(db,h,r-2)));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\PickTheCoins.in","r",stdin);
  int n;
  cin>>n;
  int *db = new int[n];
  FOR(i,0,n) cin>>db[i];
  cout<<PickDP(db,n);
}
