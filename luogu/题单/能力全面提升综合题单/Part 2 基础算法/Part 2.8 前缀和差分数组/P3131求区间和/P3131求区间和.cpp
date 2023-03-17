#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P3131
 */


int main()
{
    // i代表左侧拿几个，N个数最多左侧可以拿N-1
    // i=0,j=1 1种 l[0],r[N+1], 1~N
    // i=1,j=1&2 2种 l[0],r[N,N+1] l[0,1],r[N+1] 1~N-1,2~N
    // i=2,j=1&2&3 3种 l[0],r[N-1,N+1] l[0,1],r[N,N+1] l[0,2],r[N+1] 1~N-2,2~N-1,3~N
    // i=N-1 N种 1~N-N, 2~N-N+1...
    // 结果是求整除，因此可以通过mod化简，避免爆int
    int N,a[50005],sum[50005];
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    // 前缀和预处理+mod处理
    for (int i=1;i<=N;i++) {
        sum[i]=(sum[i-1]+a[i])%7;
    }
    // N^2复杂度，爆TLE
//    int ans=0;
//    for (int i=0;i<=N-1;i++) {
//        bool stop=false;
//        for (int j=1;j<=i+1;j++) {
//            int res=sum[N+j-i-1]-sum[j-1]+7;
//            if (res%7==0) {
//                ans=N-i;
//                stop=true;
//                break;
//            }
//        }
//        if (stop) break;
//    }
    // 直接模拟爆TLE，改思路
    // 要使sum[N+j-i-1]-sum[j-1]+7整除7，
    // 那么sum[N+j-i-1]和sum[j-1]余数一定相同
    // 那么遍历所有可能的余数0~6，找出最左侧的和最右侧的点
    // 两点距离就是最大距离
    int ans=0;
    for (int i=0;i<=6;i++) {
        int l=1,r=N;
        while (sum[l-1]!=i&&l<=N) l++;
        while (sum[r]!=i&&r>=1) r--;
        ans=max(ans,r-l+1);
    }
    printf("%d",ans);
    return 0;
}
