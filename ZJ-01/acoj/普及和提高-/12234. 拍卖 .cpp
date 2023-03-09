#include <bits/stdc++.h>


using namespace std;

/**
公司最近新研发了一种产品，共生产了n件。 N
有m个客户想购买此产品，第i个客户出价Vi元。 M
为了确保公平，公司决定要以一个固定的价格出售产品。
每一个出价不低于要价的客户将会得到产品，
余下的将会被拒绝购买。
请你找出能让公司利润最大化的售价。
输入格式:
输入第一行二个整数n(1<=n<=1000),m(1<=m<=1000)，分别表示产品数和客户数。
接下来第二行m个整数Vi(1<=Vi<=1000000)，分别表示第i个客户的出价。
输出格式:
输出一行一个整数，代表能够让公司利润最大化的售价。
样例 1 :
输入:
5 4
2 8 10 7
输出:
7
 */
#define ll long long
int main()
{
    ll N,M,p[1000];
    cin >> N >> M;
    for (ll i=0;i<M;i++) {
        cin >> p[i];
    }
    sort(p,p+M); // 升序
    // 打印数组
//    for (ll i=0;i<M;i++) {
//        printf("%lld ",p[i]);
//    }
//    printf("\n");
    ll maxn=0,maxp=0;
    for (ll i=0;i<M;i++) {
        // 没有仔细读题， 数量为不超过n件，所以要用M-i不能超过n
        ll lirun=p[i]*min(N,(M-i));
        if (maxn<lirun) {
            maxn=lirun;
            maxp=p[i];
        }
    }
    cout << maxp;
    return 0;
}
