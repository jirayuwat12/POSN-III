#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pb push_back
#define FOR(i,s,n) for(int i=s;i<n;i++)
using namespace std;

bool Compare(const pair<string,double> &a,const pair<string,double> &b){
  return a.first<b.first || (a.first==b.first && a.second < b.second);
}

int main(){
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\library.in","r",stdin);
  vector< pair<string, double> > books;
  int n;
  string name;
  double price;
  cin>>n;
  FOR(i,0,n){
    cin>>name>>price;
    books.pb({name,price});
  }
  sort(books.begin(),books.end(),Compare);
  for(auto i :books){
    cout<<i.first<<' '<<i.second<<'\n';
  }
}
