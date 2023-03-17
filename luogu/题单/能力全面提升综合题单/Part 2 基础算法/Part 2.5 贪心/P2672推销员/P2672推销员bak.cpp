#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P2672
 */
#define int long long
int N,S[100005],A[100005],ans=0,vis[100005],K;

#undef int
int main()
{
    // 爆超时
#define int long long
    scanf("%lld",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&S[i]);
    }
    for (int i=1;i<=N;i++) {
        scanf("%lld",&A[i]);
    }
    // 第一次选 X=1; 其实就是右侧选
    int max1=0; // K是一把标尺，是走路的疲劳值
    for (int i=1;i<=N;i++) {
        int res=S[i]*2+A[i];
        if (res>max1) max1=res,K=i;
    }
    vis[K]=1;
    ans+=max1; // 第一次增加的疲劳度
    printf("%lld\n",ans);
    // 第二次选 X=2;
    for (int ii=1;ii<=N-1;ii++) {
        int maxl=0,maxr=0,ml,mr;
        for (int i=1;i<=N;i++) {
            if (vis[i]==1) continue;
            if (S[i]<S[K]) {
                // 左侧找A[i]最大的，因为只用付出推销的疲劳度成本
                if (A[i]>maxl) maxl=A[i],ml=i;
            } else {
                // 右侧找 (S[i]-S[j])*2+A[i]最大的
                int res=(S[i]-S[K])*2+A[i];
                if (res>maxr) maxr=res,mr=i;
            }
        }
        if (maxl>=maxr) { // 如果在左侧找到更大的，那么标尺不变
            vis[ml]=1,ans+=maxl;
            printf("%lld\n",ans);
        } else { // 否则标尺更新为mr
            vis[mr]=1,ans+=maxr,K=mr;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
