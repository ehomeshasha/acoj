#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/1080
 */
#define int long long
struct Player {
    int a,b;
} KING, player[1005];

bool cmp(const Player &a, const Player &b)
{
    // 假设相邻两个点已经符合排序，满足最小奖赏要求
    // 那么这种排法一定比相反的排法最大奖赏要小
    // 排法1 a1,b1在前，a2,b2在后： 最大奖赏=max(S/b1,S*a1/b2)
    // 排法2 a2,b2在前，a1,b1在后： 最大奖赏=max(S/b2,S*a2/b1)
    // 假设排法1对，排法2不对，那么必然
    // max(S/b1,S*a1/b2) < max(S/b2,S*a2/b1)
    // 又由于里面有矛盾项， S*a1/b2>=S/b2
    // 因此后一个式子肯定S*a2/b1>S/b2，因此后面的max返回结果一定是S*a2/b1
    // 那么接下来，S*a2/b1肯定大于前面2个数，因为比前面两个数最大值还要大撒
    // 选一个数可以化简 S*a1/b2<S*a2/b1
    // 两边化简 a1*b1<a2*b2
    // 因此按照这个升序即可
    return a.a*a.b<b.a*b.b;
}

#undef int
int main()
{
#define int long long
    int N;
    scanf("%lld",&N);
    scanf("%lld %lld",&KING.a,&KING.b);
    for (int i=1;i<=N;i++) {
        scanf("%lld %lld",&player[i].a,&player[i].b);
    }
    sort(player+1,player+1+N,cmp);
    // 剩下的是高精度求解，不会弄，需要补充知识
    int ans=0;
    for (int i=1;i<=N;i++) {
        int result=KING.a;
        for (int j=1;j<i;j++) {
            result*=player[j].a;
        }
        result/=player[i].b;
        ans=max(ans,result);
    }
    printf("%lld",ans);
    return 0;
}
