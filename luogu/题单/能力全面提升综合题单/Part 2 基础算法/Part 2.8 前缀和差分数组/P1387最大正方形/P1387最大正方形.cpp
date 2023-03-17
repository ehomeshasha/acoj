#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1387
 */


int main()
{
    int N,M,A[105][105],sum[105][105];
    scanf("%d %d",&N,&M);
    // 假定N一定是小于等于M的
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (N<=M) scanf("%d",&A[i][j]);
            else scanf("%d",&A[j][i]); // 转换保证矩阵A一定N<=M
        }
    }
    // 新矩阵的NM
    int t;
    if (N>M) {
        t=N,N=M,M=t;// 互换N和M
    }
    // 前缀和数组
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) sum[i][j]=sum[i][j-1]+A[i][j];
    }

    // 模拟
    // 小的边一定是N
    bool stop=false;
    int ans=0;
    for (int L=N;L>0;L--) {
        // L=N，那么N就撑满，i=1,j的话从1开始，一直到M-N+1
        // L=N-1,那么i从1到2，j的话从1到M-N+2
        for (int i=1;i<=N-L+1;i++) {
            for (int j=1;j<=M-L+1;j++) {
                // 遍历每个正方形
                // 一条边是 [i,i+L-1], 另一条边是 [j,j+L-1], i和j是正方形左上顶点坐标
                bool find=true;
                for (int k=i;k<=i+L-1;k++) {
                    int r=j+L-1,l=j;
                    if (sum[k][r]-sum[k][l-1]!=L) {
                        find=false;
                        break;
                    }
                }
                if (find) {
                    ans=L;
                    stop=true;
                    break;
                }
            }
            if (stop) break;
        }
        if (stop) break;
    }
    printf("%d",ans);
    return 0;
}
