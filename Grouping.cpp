#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i=0;
  cin>>n;
  int d[n];
  int t= n;
  while (n--) cin>>d[i++];
  i--;
  sort(d,d+t);
  int B=0,A=0;
  while(i>=0){
    if(A >= B) B += d[i--];
    else A += d[i--];
  }
  cout<<abs(A-B);
}
