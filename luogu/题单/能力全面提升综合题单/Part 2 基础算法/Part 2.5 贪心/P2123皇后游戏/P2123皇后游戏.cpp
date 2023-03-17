#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P2123
 */
// 和国王游戏同样思路
// 设某个位置大臣编号为i，下一个大臣为j
// i前面所有大臣之和为x，i前面那位大臣c为y
// ci=max(y,x+ai)+bi
// cj=max(max(y,x+ai)+bi,x+ai+aj)+bj
// 化简后为cj=max(y+bi,x+ai+bi,x+ai+aj)+bj
// cj=max(y+bi+bj,x+ai+bi+bj,x+ai+aj+bj)
// i和j互换位置得到另一个排法的最大奖赏cj为
// cj=max(y+bi+bj,x+aj+bi+bj,x+ai+aj+bi)
// 要使排序更优 max(y+bi+bj,x+ai+bi+bj,x+ai+aj+bj)<=max(y+bi+bj,x+aj+bi+bj,x+ai+aj+bi)
// 相同化简 max(x+ai+bi+bj,x+ai+aj+bj)<=max(x+aj+bi+bj,x+ai+aj+bi)
// max(ai+bi+bj,ai+aj+bj)<=max(aj+bi+bj,ai+aj+bi)
// max(bi,aj)+ai+bj<=max(bj,ai)+aj+bi
// max(bi,aj)-bi-aj<=max(bj,ai)-ai-bj
// 较大的数被消掉了，只剩下较小的数
// -min(bi,aj)<=-min(bj,ai)
// min(ai,bj)<=min(bi,aj)











#define int long long
struct Node {
    int a,b,d;
} P[20005];
bool cmp(const Node &i, const Node &j)
{
//    // 如果是不同组，按组排序
//    if (i.d!=j.d) return i.d<j.d;
//    if (i.d<=0) return i.a<j.a;
//    else return i.b>j.b;
    return min(i.a,j.b)==min(i.b,j.a)?i.a<j.a:min(i.a,j.b)<min(i.b,j.a);
}

int T,N,S[20005];


#undef int
int main()
{
#define int long long
    scanf("%lld",&T);
    for (int t=0;t<T;t++) {
        scanf("%lld",&N);
        for (int i=1;i<=N;i++) {
            scanf("%lld %lld",&P[i].a,&P[i].b);
//            if (P[i].a>P[i].b) P[i].d=1;
//            else if (P[i].a<P[i].b) P[i].d=-1;
//            else P[i].d=0;
        }
        sort(P+1,P+1+N,cmp);
        int sum=0;
        for (int i=1;i<=N;i++) {
            sum+=P[i].a;
            S[i]=max(S[i-1],sum)+P[i].b;
        }
        printf("%lld\n",S[N]);

    }
    return 0;
}
