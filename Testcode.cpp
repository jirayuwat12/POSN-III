#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i,s,b) for(it i=s;i<b;i++)
#define FORR(i,s,b) for(int i=s;i>b;i--)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef int64_t it;

struct pp2{
    double x, y;
    bool operator<( const pp2 &k )const{
        if( y == k.y )return x < k.x;
        else return y < k.y;
    }
}po2[100100];

int main(){
  po2[0].x = 0;
  po2[0].y = 1;
  cout<<po2[0].x;

}
