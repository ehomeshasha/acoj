#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P3397
 */
int N,M,diff[1005][1005];

int main()
{
    // 先打标记， 参考1维差分数组， 需要打4个点
    // x1,y1+=v, x2+1,y1-=v, x1,y2+1-=v, x2+1,y2+1+=v
    // 然后对二维差分数组求前缀和
    scanf("%d %d",&N,&M);
    for (int i=1;i<=M;i++) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        diff[x1][y1]+=1;
        diff[x2+1][y1]-=1;
        diff[x1][y2+1]-=1;
        diff[x2+1][y2+1]+=1;
    }
    // 求前缀合
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            diff[i][j]=diff[i][j-1]+diff[i][j];
        }
        for (int j=1;j<=N;j++) {
            diff[i][j]=diff[i-1][j]+diff[i][j];
        }
    }
    // 打印输出
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d ",diff[i][j]);
        }
        printf("\n");
    }
    return 0;
}
