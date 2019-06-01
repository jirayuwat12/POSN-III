/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
/*
TASK: nbk48.cpp
LANG: C++
AUTHOR: Ith Ithsarasak na ayuthaya
CENTER: PSUS
*/
#include<bits/stdc++.h>

using namespace std;
unordered_map<int,int> idx;
int sum[100100];
int n, qe, allsum;
int cost[100100], mo[100100];
int mx;
int main()
{
    scanf("%d %d",&n,&qe);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&cost[i]);
        allsum += cost[i];
        sum[i] = sum[i-1] + cost[i];
        idx[sum[i]] = i;
    }
    for( int i = n - 1 ; i >= 1 ; i-- ){
        if( sum[i+1] < sum[i] ){
            sum[i] = sum[i+1];
        }
    }
    for( int i = 0 ; i < qe ; i++ ){
        scanf("%d",&mo[i]);
    }
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%d\n",sum[i]);
    }*/
    sort( sum + 1, sum + n + 1 );
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%d ",idx[sum[i]]);
    }*/
    for( int i = 0 ; i < qe ; i++ ){
        if( mo[i] < sum[1] ){
            printf("0\n");
        }
        else if( mo[i] > allsum ){
            printf("%d\n",n);
        }
        else{
            int id = upper_bound( sum + 1, sum + 1 + n, mo[i] ) - sum;
            //printf("id : %d\n",id);
            int suu = sum[id-1];
            printf("%d\n",idx[suu]);
        }
    }
    return 0;
}
