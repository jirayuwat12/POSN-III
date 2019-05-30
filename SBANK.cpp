#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>

// spoj - Sbank
using namespace std;

int main(){
  // string tmp;
  // getline (cin >> ws,tmp);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t,i=-1,j,n;
  cin>>t;
  vector<map<string,int>> fre(t);
  string temp;
  while(++i<t){
    cin>>n;
    j=-1;
    while(++j<n){
      getline(cin>>ws,temp);
      fre[i][temp]++;
    }
  }
  cout<<"\n";
  i=-1;
  while(++i<t){
    for(auto j : fre[i]){
      cout<<j.first.c_str()<<' '<<j.second<<'\n';
    }cout<<"\n";
  }

}
