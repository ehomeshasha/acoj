#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P5194
 */
#define int long long
int N,C,a[1005],sum[1005],ans=0,t; // 1<=N<=1000, C<2^30, 从第三个数开始，后面的数>=前面两个数之和，不下降序列

void dfs(int idx, int w)
{
    if (w>C) return;
    if (sum[idx-1]+w<=C) { // 剪枝
        ans=max(ans,sum[idx-1]+w);
        return;
    }
    ans=max(ans,w);
    for (int i=idx-1;i>=1;i--) {
        dfs(i,w+a[i]);
    }
}

#undef int
int main()
{
#define int long long
    // 考察1 斐波那契数列特点， 增加非常快， n>40就超过2^32了
    // 考察2 dfs
    scanf("%lld %lld",&N,&C);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&t);
        if (t>C) { // 砝码重点比C大，无效砝码过滤
            N=i-1;
            break;
        }
        a[i]=t;
        sum[i]=sum[i-1]+a[i];
    }
    // 由后往前搜索
    dfs(N+1,0);
    cout << ans;
    return 0;
}
