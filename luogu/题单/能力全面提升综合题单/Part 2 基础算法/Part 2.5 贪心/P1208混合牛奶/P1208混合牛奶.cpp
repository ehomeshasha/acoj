#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1208
 */
struct Milk {
    int p,a;
} MILK[5000];

bool cmp(const Milk &a, const Milk &b)
{
    return a.p<b.p;
}

int main()
{
    int N,M,n=0,tot=0;
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> MILK[i].p >> MILK[i].a;
    }
    sort(MILK,MILK+M,cmp);
    for (int i=0;i<M;i++) {
        Milk m=MILK[i];
        int add=min(N-n,m.a);
        n+=add;
        tot+=add*m.p;
        if (n==N) break; // 已经采购到N个牛奶，采购结束
    }
    cout << tot;
    return 0;
}
