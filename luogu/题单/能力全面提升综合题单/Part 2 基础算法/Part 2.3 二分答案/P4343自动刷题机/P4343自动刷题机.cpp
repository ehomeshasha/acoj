#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P4343

4 2
2
5
-3
9

3 7
 */
#define int long long
const int MAXN=100005;
int L,K,X[MAXN],maxn;

int cal(int n)
{
    int sum=0,cnt=0;
    for (int i=1;i<=L;i++) {
        if (X[i]>=0) sum+=X[i];
        else sum-=min(-X[i],sum); // 小于0情况
        if (sum>=n) {
            cnt++,sum=0;
        }
    }
    return cnt;
}

#undef int
int main()
{
#define int long long
    scanf("%lld %lld",&L,&K);
    for (int i=1;i<=L;i++) {
        scanf("%lld", &X[i]);
        if (X[i]>0) maxn+=X[i];
    }
    int l=1,r=maxn+1;
    // n越小，那么切题越多
    // 用两次二分， 一次求解出得到等于k时的l，r，mid
    // 然后从该状态开始
    // 分别求解最大值和最小值
    while (l<=r) {
        int mid=l+(r-l)/2;
        int k=cal(mid);
        if (k<K) { // 如果切的题比K少，需要减小n
            r=mid-1;
        } else if (k>K) { // 如果切的题比K多，需要增加n
            l=mid+1;
        } else { // 如果切的题相等，那么尝试增加求解最大值
            break;
        }
    }
    // 求解最大值
    int l1=l,r1=r,maxx;
    bool hasmax= false;
    while (l1<=r1) {
        int mid=l1+(r1-l1)/2;
        int k=cal(mid);
        if (k<K) { // 如果切的题比K少，需要减小n
            r1=mid-1;
        } else if (k>K){
            // 如果切的题比K多，需要增加n
            // 如果切的题相等，那么尝试增加求解最大值
            maxx=mid,l1=mid+1;
        } else {
            maxx=mid,l1=mid+1,hasmax=true;
        }
    }
    // 求解最小值
    int l2=l,r2=r,minn;
    bool hasmin= false;
    while (l2<=r2) {
        int mid=l2+(r2-l2)/2;
        int k=cal(mid);
        if (k<K) { // 如果切的题比K少，需要减小n
            minn=mid,r2=mid-1;
        } else if (k>K) {
            // 如果切的题比K多，需要增加n
            l2=mid+1;
        } else { // 如果相等要尝试减小来找更小值
            minn=mid,r2=mid-1,hasmin=true;
        }
    }
    if (!hasmin&&!hasmax) printf("-1");
    else if (hasmin&&!hasmax) printf("%lld %lld",minn,minn);
    else if (!hasmin&&hasmax) printf("%lld %lld",maxx,maxx);
    else printf("%lld %lld",minn,maxx);
    return 0;
}
