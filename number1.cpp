#include <iostream>
#include <math.h>
using namespace std;
/*
SPOJ-Prime number genearator
cout all prime number from a to b
*/
int main(){
  int i,n,k,j;
  bool ck;
  cin>>n;
  int aans[n][2];
  for(i=0;i<n;i++){
    cin>>aans[i][0]>>aans[i][1];
  }
  for(k=0;k<n;k++){
    for(i=aans[k][0];i<=aans[k][1];i++){
      ck = true;
      for(j=2;j<=sqrt(i);j++){
        if(!(i%j)) ck = false;
      }
      if(ck && i!= 1) cout<<i<<endl;
    }
    cout<<endl;
  }
}
/*
10001
100
*/
