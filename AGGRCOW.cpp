#include <iostream>
#include <algorithm>

using namespace std;
#define FOR(i,s,n) for(auto i=s;i<n;i++)
#define FORR(i,s,n) for(auto i=s;i>n;i--)
#define pb push_back
//function used for binary search

bool F(int c,int *db,int dist,int n){
  int st = db[0];c--;
  FOR(i,1,n){
    if(db[i] - st >= dist) st = db[i],c--;
    if(c==0)  return true;
  }
  return false;
}

int main(){
  int t;
  //number of test-cases
  scanf("%d",&t);
  while(t--){
    int n,c;
    scanf("%d %d",&n,&c);
    int *db = new int[n];
    //cin all each data in test-cases
    FOR(i,0,n) scanf("%d",&db[i]);
    sort(db,db+n);
    //bbinary search
    int h=0,r=db[n-1],mid;
    while(h<r-1){
      mid =(h+r)/2;
      if(F(c,db,mid,n)) h = mid;
      else r = mid -1;
    }
    //cout ans
    if(F(c,db,r,n))cout<<r<<'\n';
    else cout<<h<<'\n';
  }
}
/*
test case(s)
1
5 3
1 2   4       8 9
h r
1 8
1 4
4 4
*/
