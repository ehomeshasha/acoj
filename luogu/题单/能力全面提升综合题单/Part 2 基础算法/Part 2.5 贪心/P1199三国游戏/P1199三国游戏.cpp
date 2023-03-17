#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1199
 */
int main()
{
    int N,m[505][505];
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            int w;
            scanf("%d", &w);
//            edge[K++]=Edge{i,j,w};
            m[i][j]=w,m[j][i]=w;
        }
    }
    // 小涵怎么选收益最高，就是求选出的两两默契值尽可能大
    // 博弈论问题，不要去模拟过程，想办法分析获胜的方式
    // 思考
    // 1. 我是先手还是后手
    // 2. 怎么样是一定是胜者
    int ans=0;
    for (int i=1;i<=N;i++) {
        sort(m[i]+1,m[i]+1+N);
        // 引诱电脑去拿最大的， 我是先手，我肯定能拿到次大的，所以就是找次大的最大值
        ans=max(ans,m[i][N-1]);
    }
    printf("1\n%d",ans);
    return 0;
}
