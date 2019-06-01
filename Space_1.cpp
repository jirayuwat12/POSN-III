/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
/*
TASK: Space.cpp
LANG: C++
AUTHOR: Ith Ithsarasak na ayuthaya
CENTER: PSUS
*/
#include<bits/stdc++.h>

using namespace std;
struct po{
    int x, y;
}tt;
queue<po> q;
char ma[10002][2002];
int n, m, cnt, wx[4] = { 1, 0, -1, 0 }, wy[4] = { 0, 1, 0, -1 }, one, two, three;
int minx,miny,maxx,maxy;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%s",ma[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ;j < n ; j++ ){
            if( ma[i][j] == '1' ){
                q.push({ i, j });
                minx = 1e9, miny = 1e9, maxx = -1e9, maxy = -1e9;
                cnt = 0;
                while( !q.empty() ){
                    cnt++;
                    tt = q.front();
                    q.pop();
                    ma[tt.x][tt.y] = '0';
                    minx = min( minx, tt.x );
                    miny = min( miny, tt.y );
                    maxx = max( maxx, tt.x );
                    maxy = max( maxy, tt.y );
                    for( int k = 0 ; k < 4 ; k++ ){
                        if( ma[tt.x + wx[k]][tt.y+wy[k]] == '1' && tt.x + wx[k] < m && tt.x + wx[k] >= 0 && tt.y + wy[k] < n && tt.y + wy[k] >= 0 ){
                            q.push({ tt.x + wx[k], tt.y + wy[k] });
                            ma[tt.x+wx[k]][tt.y+wy[k]] = '0';
                        }
                    }
                }
                if( maxx - minx == maxy - miny ){
                    if( cnt == ( maxx - minx + 1 ) * ( maxx - minx + 1 ) ){
                        one ++;
                    }
                    else two++;
                }
                else three++;
            }
        }
    }
    printf("%d %d %d",one,two,three);
    return 0;
}
