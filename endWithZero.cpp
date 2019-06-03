#include "iostream"
#include <cstdint>
typedef int64_t in;
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  in n,zero=0;
  cin >> n;
  in m=5;
  while(true){
    if(n/m==0)  break;
    else{
        zero+=n/m;
        m=m*5;
    }
  }
  cout << zero;
}
