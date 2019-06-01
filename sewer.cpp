#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\sewer\\6.in","r",stdin);
  int n,m;
  cin>>n>>m;
  int ans[n][m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans[i][j] = 0;
  char db[n][m] ;
  ans[0][0] = 1;
  int a[2];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>db[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int x = i+1,y = j+1;
      switch(db[i][j]){
        case 'B' : ans[x][j] += ans[i][j];ans[i][y] += ans[i][j];
          break;
        case 'R' : ans[i][y] += ans[i][j];
          break;
        case 'D' : ans[x][j] += ans[i][j];
          break;
        default : break;
      }
      cout<<ans[i][j]<<' ';
      if(ans[i][j]==2) cout<<i+j+1<<'\n'<<i+1<<' '<<j+1,i=n,j=m;
    }
    cout<<endl;
  }
}
