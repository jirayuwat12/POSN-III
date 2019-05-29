#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>
using namespace std;
typedef int64_t ll;
/*
SPOJ-Ada and Friends
input name and expended and choose man(s) to decrease all expended
*/
int main(){
  freopen("C:\\Users\\Lenovo\\Desktop\\POSN III\\ADAFRIEN.in","r",stdin);
  priority_queue<ll,vector<ll>,less<ll>> pq;
  int n,i,j=0,k=0;
  ll sum=0,pri;
  cin>>n>>i;
  unordered_map<string,ll> m;
  string name;
  while(j++<n){
    cin>>name>>pri;
    m[name] +=pri;
  }
  for(auto b : m){
    pq.push(b.second);
  }
  while(k++<i && !pq.empty()){
    sum += pq.top();
    pq.pop();
  }
  cout<<sum;
}
