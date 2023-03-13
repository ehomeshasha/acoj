#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1226

2 10 9

2^10 mod 9=7
 */
// 3^10
// 3^5*3^5
// (3^2*3^2)*3*(3^2*3^2)*3
// 3^1*3^1*3*3*3 a=3, b=1;
//

// f(a,b)=fx(a,b/2)*fx(a,b/2)*a^b%2
// f(a,1)=fx(a,0)*fx(a,0)*a
// f(a,2)=fx(a,1)*fx(a,1)*1=(a*a)
// f(a,4)=(a*a)(a*a)
// f(a,8)=((a*a)(a*a))*((a*a)(a*a))
#define int long long
int ksm(int a, int b, int p)
{
    int res=1;
    while(b!=0) {
        if (b%2==1) res=(res*a)%p;
        a=(a*a)%p,b=b/2;
    }
    return res;
}

#undef int
// 快速幂
int main()
{
#define int long long
    int a,b,p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld",a,b,p,ksm(a,b,p));
    return 0;
}
