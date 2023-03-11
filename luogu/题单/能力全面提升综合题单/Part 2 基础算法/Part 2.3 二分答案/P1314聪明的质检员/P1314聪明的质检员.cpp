#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1314

5 3 15
1 5
2 5
3 5
4 5
5 5
1 5
2 4
3 3

10
 */
#define int long long
int N,M,S,w[200005],v[200005],L[200005],R[200005],ans;
int pre_n[200005],pre_v[200005];

// 使用前缀和效率更高
//int cal_yi(int li, int ri, int W)
//{
//    int res=0;
//    for (int j=li;j<=ri;j++) {
//        if (w[j]>=W) {
//            int sum=0;
//            for (int k=li;k<=ri;k++) {
//                if (w[k]>=W) sum+=v[k];
//            }
//            res+=sum;
//        }
//    }
//    return res;
//}

int cal_y(int W)
{
    memset(pre_n,0,sizeof(pre_n));
    memset(pre_v,0,sizeof(pre_v));
    // 这里使用前缀和
    for (int i=1;i<=N;i++) {
        if (w[i]>=W) pre_n[i]=pre_n[i-1]+1,pre_v[i]=pre_v[i-1]+v[i];
        else pre_n[i]=pre_n[i-1],pre_v[i]=pre_v[i-1];
    }
    int res=0;
    for (int i=1;i<=M;i++) {
        res+=(pre_n[R[i]]-pre_n[L[i]-1])*(pre_v[R[i]]-pre_v[L[i]-1]);
    }
    return res;
}
#undef int
int main()
{
#define int long long
    scanf("%lld %lld %lld\n",&N,&M,&S);
    int l=0x3f3f3f3f,r=0;
    for (int i=1;i<=N;i++) {
        scanf("%lld %lld\n",&w[i],&v[i]);
        r=max(r,w[i]); // 得出右边界
        l=min(l,w[i]); // 得出左边界
    }
    for (int i=1;i<=M;i++) {
        scanf("%lld %lld\n",&L[i],&R[i]);
    }
    r=r+1;
    int ans1,ans2;
    while (l<=r) {
        int mid=l+(r-l)/2;
        int y=cal_y(mid); // mid和y负相关
        if (y-S>0) {
            ans1=y-S,l=mid+1;
        } else {
            ans2=S-y,r=mid-1;
        }
    }
    ans=min(ans1,ans2);
    printf("%lld", ans);
    return 0;
}
