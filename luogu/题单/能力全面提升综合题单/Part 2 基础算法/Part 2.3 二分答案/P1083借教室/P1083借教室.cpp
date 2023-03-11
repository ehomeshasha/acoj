#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1083

4 3
2 5 4 3
2 1 3
3 2 4
4 2 4

-1
2
 */
#define int long long
const int MAXN=1000005;
int N,M,tot[MAXN],d[MAXN],s[MAXN],t[MAXN],diff[MAXN],pre[MAXN],ans;

// 区间算法：前缀和
// 1 2 4 6 8 13
// 2+4+6+8
// pre[5]-pre[1],pre[5]=1+2+4+6+8, pre[1]=1
//
//    int pre[1000005];
//    for (int i=1;i<N;i++) {
//        pre[i]=pre[i-1]+a[i];
//    }
// 逆运算，差分数组
// 0 0 0 0 0 0
// 3-5区间加2
// 修改l=diff和r+1=-diff
// 0 0 2 0 0 -2 对这个数组求前缀和
// 0 0 2 2 2 0
// 多次区间修改， 无非是多次进行修改l和r+1操作
// 最终得到的数组求前缀和
bool check(int x)
{
    memset(diff, 0, sizeof(diff));
    memset(pre, 0, sizeof(diff));
    // 求差分数组
    for (int i=1;i<=x;i++) {
        diff[s[i]]+=d[i],diff[t[i]+1]+=-d[i]; // 累加
    }
    // 求前缀和
    for (int i=1;i<=N;i++) {
        pre[i]=pre[i-1]+diff[i];
        if (tot[i]<pre[i]) return false; // 看有没有不够扣的
    }
    return true;
}
#undef int
int main()
{
#define int long long
    // 10^12次方复杂度，肯定会超时
    // 累计的简化
    // 怎么简化每个tot的值的扣减
    // 先二分
    // 二分完判断， 假如区间加和
    // 暴力解法 45分
//    scanf("%d %d",&N,&M);
//    for (int i=1;i<=N;i++) scanf("%d", &tot[i]);
//    for (int i=1;i<=M;i++) {
//        scanf("%d %d %d",&d,&s,&t);
//        for (int j=s;j<=t;j++) {
//            if (tot[j]<d) {
//                printf("-1\n%d",i);
//                return 0;
//            }
//            tot[j]-=d;
//        }
//    }
//    printf("0");

    // 差分数据（前缀和的逆运算）+二分
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++) scanf("%d", &tot[i]);
    for (int i=1;i<=M;i++) scanf("%d %d %d",&d[i],&s[i],&t[i]);
    // 二分答案
    int l=1,r=M;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if (check(mid)) { // 如果一半教室够用，则mid太小，需要增加
            l=mid+1;
        } else { // 如果教室不够用，尝试找更小的mid
            ans=mid,r=mid-1;
        }
    }
    if (ans==0) printf("0");
    else printf("-1\n%d", ans);
    return 0;
}
