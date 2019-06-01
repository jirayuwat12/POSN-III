#include <iostream>
#include <math.h>
using namespace std;

struct n {
  double x,y;
}db[100100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  scanf("%d",&q);
  while(q--){
    int n,r,d;
    scanf("%d %d %d",&n,&r,&d);
    for(int i=0;i<n;i++){
      scanf("%lf %lf",&db[i].x,&db[i].y);
    }int ch =0;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            double te1  = ( db[i].x - db[j].x ) * ( db[i].x - db[j].x );
            double te2  = ( db[i].y - db[j].y ) * ( db[i].y - db[j].y );
            double te3 = sqrt( te1 + te2 ) - (2.0*r);
            if( d - te3 > 1e-6 ){
                ch = 1;
                break;
            }
        }
        if( ch )break;
    }
    if( ch )printf("N\n");
    else printf("Y\n");
  }
}
