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


int main()
{
    int n,m,X,Y;
    long a[30][30]={0},ma[30][30]={0};
    // 输入
    cin >> n >> m >> X >> Y;
    n+=2;m+=2;X+=2;Y+=2;
    // 哪些不能走
    ma[X][Y]=1;
    ma[X-1][Y-2]=1;
    ma[X-2][Y-1]=1;
    ma[X-2][Y+1]=1;
    ma[X-1][Y+2]=1;
    ma[X+1][Y-2]=1;
    ma[X+2][Y-1]=1;
    ma[X+2][Y+1]=1;
    ma[X+1][Y+2]=1;
    // 边界赋值, 可省略因为可以由下面的递推出来
//    for (int i=2;i<30;i++) {
//        a[2][i]=1;
//        a[i][2]=1;
//    }
    // 往右递推、往下递推
    for (int i=2;i<=n;i++) {
        for (int j=2;j<=m;j++) {
            if (i==2&&j==2) {
                a[i][j]=1;
                continue;
            }
            if (ma[i][j]==1) {
                a[i][j]=0;
                continue;
            }
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }

    cout << a[n][m] << endl;
    return 0;
}