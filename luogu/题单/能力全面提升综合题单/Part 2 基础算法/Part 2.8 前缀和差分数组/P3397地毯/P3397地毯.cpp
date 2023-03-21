#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P3397
 */
// 最多100万个点，因此必须每个点的计数要线性算出，否则一定爆TLE
// 针对每个点做前缀和
// xi,yi的点
struct Box {
    int x1,y1,x2,y2;
} d[1005];
int N,M,pre[1005][1005],sum[1005][1005];

int main()
{
    // 格式是NxN
    scanf("%d %d",&N,&M); // N是行，M是列
    for (int i=1;i<=M;i++) {
        // M个地毯
        scanf("%d %d %d %d", &d[i].x1, &d[i].y1, &d[i].x2, &d[i].y2);
    }
    // 差分数组
    // 假设N行为N个差分数组，每个差分数组为M个元素，默认值都是0
    // 第一个差分数组pre[1]
    for (int i=1;i<=M;i++) {
        // 对差分数组， y1~y2是 x1到x2个差分数组里面的要处理的起始结束点， 每次处理+1
        int x1=d[i].x1,x2=d[i].x2,y1=d[i].y1,y2=d[i].y2;
        for (int j=x1;j<=x2;j++) {
            pre[j][y1]++,pre[j][y2+1]--;
        }
    }
    //  0 -1 0 0 0 1
    //  0 0 -1 0 1 0
    //  0 -1 -2 -2 -1 0
    // 对差分数组求前缀和
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            pre[i][j]=pre[i][j-1]+pre[i][j];
        }
    }
    // 输出结果
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (j==N) printf("%d",pre[i][j]);
            else printf("%d ",pre[i][j]);
        }
        printf("\n");
    }
    return 0;
}
