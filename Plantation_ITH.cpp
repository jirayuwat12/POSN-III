/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
/*
TASK: Plantation.cpp
LANG: C++
AUTHOR: Ith Ithsarasak na ayuthaya
CENTER: PSUS
*/
#include<bits/stdc++.h>

using namespace std;
struct pp{
    double x, y;
    bool operator<( const pp &k )const{
        if( x == k.x )return y < k.y;
        else return x < k.x;
    }
}po[100100];
struct pp2{
    double x, y;
    bool operator<( const pp2 &k )const{
        if( y == k.y )return x < k.x;
        else return y < k.y;
    }
}po2[100100];
int q, n;
double r, d;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d %lf %lf",&n,&r,&d);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%lf %lf",&po[i].x,&po[i].y);
            po2[i].x = po[i].x;
            po2[i].y = po[i].y;
        }
        int ch = 0;
        if( n <= 300 ){
            for( int i = 0 ; i < n ; i++ ){
                for( int j = i + 1 ; j < n ; j++ ){
                    double te1  = ( po[i].x - po[j].x ) * ( po[i].x - po[j].x );
                    double te2  = ( po[i].y - po[j].y ) * ( po[i].y - po[j].y );
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
        else{
            sort( po, po + n );
            sort( po2, po2 + n );
            for( int i = 0 ; i < n - 1 ; i++ ){
                double te1  = ( po[i].x - po[i+1].x ) * ( po[i].x - po[i+1].x );
                double te2  = ( po[i].y - po[i+1].y ) * ( po[i].y - po[i+1].y );
                double te3 = sqrt( te1 + te2 ) - (2.0*r);
                //printf("%f\n",te3);
                if( d - te3 > 1e-6 ){
                    ch = 1;
                    break;
                }
            }
            //printf("\n");
            for( int i = 0 ; i < n - 1 ; i++ ){
                double te1  = ( po2[i].x - po2[i+1].x ) * ( po2[i].x - po2[i+1].x );
                double te2  = ( po2[i].y - po2[i+1].y ) * ( po2[i].y - po2[i+1].y );
                double te3 = sqrt( te1 + te2 ) - (2.0*r);
                //printf("%f\n",te3);
                if( d - te3 > 1e-6 ){
                    ch = 1;
                    break;
                }
            }
            if( !ch )printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
