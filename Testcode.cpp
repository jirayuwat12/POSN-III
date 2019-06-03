#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i,s,b) for(it i=s;i<b;i++)
#define FORR(i,s,b) for(int i=s;i>b;i--)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef int64_t it;
int *db;
int n,t;

void print(string s,map<int,bool> used){
  if(s.size() == t) cout<<s<<endl;
  else for(int j=0;j<n;j++) {
    auto found = s.find(to_string(db[j]));
    if(found == string :: npos) {
      used[db[j]] = true;
      print(s+to_string(db[j]),used);
    }
  }
}

int main(){
  cin>>n>>t;
  db = new int[n];
  for(int i=0;i<n;i++) cin>>db[i];
  map<int,bool> m;
  string s;
  print(s,m);
}
