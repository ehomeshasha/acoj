#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P2280
 */
int N1,N=5002,M,sum[5005][5005],d[5005][5005],ans=0;

int main()
{
    // 二维前缀和， 计算所有点之和
    // 正方形左上x1,y1, 右下x2,y2
    // x1,y1最小值为1,最大值为5001
    // x2,y2最小值为2,最大值为5002
    scanf("%d %d",&N1,&M);
    for (int i=1;i<=N1;i++) {
        int x,y,v;
        scanf("%d %d %d",&x,&y,&v);
        sum[x+1][y+1]+=v;
    }
    // 求二维前缀和
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            sum[i][j]=sum[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    for (int i=M;i<=N;i++) {
        for (int j=M;j<=N;j++) {
            // i,j是右下角，矩形面积为
            // sum[i][j]-sum[i-M][j]-sum[i][j-M]+sum[i-M][j-M]
            ans=max(ans, sum[i][j]-sum[i-M][j]-sum[i][j-M]+sum[i-M][j-M]);
        }
    }
    printf("%d",ans);
    return 0;
}
