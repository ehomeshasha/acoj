#include <bits/stdc++.h>


using namespace std;

/**
如图所示的数字三角形，从顶部出发，在每一结点可以选择向左走或得向右走，一直走到底层，要求找出一条路径，使路径上的值最大。
输入格式:
第一行是数塔层数N(1<=N<=1000)。
第二行起，按数塔图形，有一个或多个的整数，表示该层节点的值，共有N行。
输出格式:
输出最大值。
样例 1 :
输入:
5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11


输出:
86
 */
const int MAXN=1005;
int N,grid[MAXN][MAXN]={0},dp[MAXN][MAXN]={0};


int main()
{
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=i;j++) {
            cin >> grid[i][j];
        }
    }
    int maxx=0;
    dp[1][1]=grid[1][1];// 起始点1,1
    for (int i=2;i<=N;i++) {
        for (int j=1;j<=i;j++) {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+grid[i][j];
        }
    }
    for (int j=1;j<=N;j++) {
        if (maxx<dp[N][j]) maxx=dp[N][j];
    }
    cout << maxx;
    return 0;
}
