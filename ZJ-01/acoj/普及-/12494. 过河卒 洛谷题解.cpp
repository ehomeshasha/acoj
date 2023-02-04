#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/**
12494. 过河卒
https://www.acoj.com/problems/12494
 */

long long a,b,n,m,data[23][23]={0},ma[23][23]={0};
void bj(long long x,long long y){
    ma[x][y]=1;
    ma[x-1][y-2]=1;
    ma[x-2][y-1]=1;
    ma[x-2][y+1]=1;
    ma[x-1][y+2]=1;
    ma[x+1][y-2]=1;
    ma[x+2][y-1]=1;
    ma[x+2][y+1]=1;
    ma[x+1][y+2]=1;
}
int main(){
    scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
    a+=2;b+=2;n+=2;m+=2;
    bj(a,b);
    data[2][2]=1;
    for(int i=2;i<=n+1;i++){
        for(int j=2;j<=m+1;j++){
            if(i==2&&j==2)continue;
            if(ma[i][j]==0)data[i][j]=data[i-1][j]+data[i][j-1];
        }
    }
    printf("%lld",data[n][m]);
    return 0;
}