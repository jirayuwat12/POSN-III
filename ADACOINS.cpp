#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\ADACOINS.in","r",stdin);
  int n,q,st,stt;
  cin>>n>>q;
  vector<int> db;
  for(int i=0;i<n;i++){
    cin>>st;
    db.push_back(st);
  }
  unordered_set<int> s[q];
  for(int i=0;i<q;i++){
    s[i].clear();
    cin>>st>>stt;
    if(stt >=n ) stt = n-1;
    for(int j=st-1;j<stt;j+\+){
      s[i].insert(db[j]);
    }
  }
  for(int i=0;i<q;i++){
    cout<<s[i].size()<<'\n';
  }
}
