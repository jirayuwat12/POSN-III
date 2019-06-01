/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
using namespace std;
const long long h=987654321;
unordered_map<long long,int> block_chain;
int T,Q,N,a,b;

long long hash_dat[3000];
int main(){
    cin>>T>>Q;
    hash_dat[1]=h;
    for(int i=2;i<3000;i++)hash_dat[i]=hash_dat[i-1]*h;
    for(int i=0;i<T;i++){

        cin>>N;

        long long hashed=0;
        for(int j=0;j<N-1;j++){
            cin>>a>>b;
            hashed+=hash_dat[a+b];
            //cout<<hashed<<endl;
        }
        block_chain[hashed]++;


    }

    /*for( pair<long long,int> h:block_chain){
        cout<<h.first<<" "<<h.second<<endl;
    }*/
    for(int i=0;i<Q;i++){
        cin>>N;
        long long hashed=0;
        for(int j=0;j<N-1;j++){
            cin>>a>>b;
            hashed+=hash_dat[a+b];
        }
        cout<<block_chain[hashed]<<endl;
    }

 return 0;
}
