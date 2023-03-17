#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P2672
 */
int n,sum[100010],q[100010],h[100010];//n 疲劳前缀和 前i个最大值 后i个最大值
struct node{
    int s;//距离
    int a;//疲劳
}v[100010];
bool cmp(node x,node y){return x.a>y.a;}
int main()
{
    // 核心思想， 可以证明，那么选前i个，要么选前i-1个，然后再到右边找一个最大的
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i].s);
    for(int i=1;i<=n;i++)scanf("%d",&v[i].a);
    sort(v+1,v+1+n,cmp);//按疲劳排序
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i].a; // 前i个推销疲劳度之和
    for(int i=1;i<=n;i++)q[i]=max(q[i-1],2*v[i].s);// 前i个最大距离*2得到的疲劳度
    for(int i=n;i>=1;i--)h[i]=max(h[i+1],2*v[i].s+v[i].a);
    // 如果i=1,那么是选1个，找1~N中疲劳度最大的，i=2，那么第一个已经被选了，需要再选1个，那么就是找2~N中疲劳度最大的
    // 那么i=k，就是找k~N中疲劳度最大的，可以推导出上面的式子
    for(int i=1;i<=n;i++)printf("%d\n",max(sum[i]+q[i],sum[i-1]+h[i]));
    return 0;
}