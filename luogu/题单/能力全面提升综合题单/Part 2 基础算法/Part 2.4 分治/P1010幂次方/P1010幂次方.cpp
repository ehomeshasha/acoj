#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1010

1315
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

1315求最高幂
二分法求最高幂


 */
int ksm(int a, int b)
{
    int res=1;
    while(b!=0) {
        if (b%2==1) res=res*a;
        a=a*a;
        b=b/2;
    }
    return res;
}

int find_mi(int n)
{
    // n=1,mi=0
    // n=2,mi=1
    // n=3,mi=1
    // n=4,mi=2
    // n=5,mi=2
    int res=2,mi=0;
    while(res<=n) {
        res*=2,mi++;
    }
    return mi;
}

void mprint(int n)
{
    while (true) {
        int mi=find_mi(n);
        int n1=ksm(2,mi);
        n=n-n1;
        if (mi==0) {
            printf("2(0)");
        } else if (mi==1) {
            printf("2");
        } else if (mi==2) {
            printf("2(2)");
        } else {
            printf("2(");
            mprint(mi);
            printf(")");
        }
        if (n!=0) printf("+");
        if (n==0) break;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    // 137
    // 2(2(2)+2+2(0))+2(2+2(0))+2(0)
    mprint(N);
    return 0;
}
