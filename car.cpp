#include <stack>
#include <iostream>

using namespace std;
int mapping [101][41];
int ans     [101][41];

int mapp(int x,int y,int m,int t){
  if(y < t && x< m && x >-1) {
    ans[y+1][x-1] = max(ans[y+1][x-1],ans[y][x]+mapping[y+1][x-1]);
    mapp(x-1,y+1,m,t);
    ans[y+1][x] = max(ans[y+1][x],ans[y][x]+mapping[y+1][x]);
    mapp(x,y+1,m,t);
    ans[y+1][x+1] = max(ans[y+1][x+1],ans[y][x]+mapping[y+1][x+1]);
    mapp(x+1,y+1,m,t);
  }
  return 0;
}

int main(){
  int m,n,t,x,y;
  cin>>m>>n>>t;
  n--;
  stack<int> s;
  for(int i=0;i<t;i++)  for(int j=0;j<m;j++)  cin>>mapping[i][j],mapping[i][j] = (!mapping[i][j])? 1:0;
  for(int i=n-1;i<=n+1;i++) if(i>=0 && i<m) ans[0][i] = mapping[0][i];
  mapp(n-1,0,m,t);
  mapp(n,0,m,t);
  mapp(n+1,0,m,t);
  for(int i=0;i<m;i++) if(ans[t-1][i] == t) x = i;
  y = t-1;
  while(y--){
    if(x> n){
      if(ans[y][x-1]==t-1) x--,s.push(2);
      else if(ans[y][x] == t-1) s.push(3);
      else x++,s.push(1);
    }else if(x<n){
      if(ans[y][x+1]==t-1) x++,s.push(1);
      else if(ans[y][x] == t-1) s.push(3);
      else x--,s.push(2);
    }else {
      if(ans[y][x] == t-1) s.push(3);
      else if(ans[y][x-1]==t-1) x--,s.push(2);
      else x++,s.push(1);
    }t--;
  }if(x>n){
    s.push(2);
  }else if(x<n){
    s.push(1);
  }else {
    s.push(3);
  }
  while(!s.empty()) cout<<s.top()<<endl,s.pop();
}
/*
10 1 15
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1


*/
