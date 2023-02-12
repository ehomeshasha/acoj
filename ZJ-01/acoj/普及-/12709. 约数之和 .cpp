#include <bits/stdc++.h>


using namespace std;

/**
给定n个正整数ai，请你输出这些数的乘积的约数之和，答案对1000000007取模。
输入格式:
第一行包含整数n。
接下来n行，每行包含一个整数ai。
输出格式:
输出一个整数，表示所给正整数的乘积的约数之和，答案需对10^9+7取模。
限制:
1≤n≤100 ,
1≤ai≤2∗10^9
样例 1 :
输入:
3
2
4
5
输出:
90
 */
map<long long,long long> m;

void add_m(long long key)
{
    if (m.count(key)==0) m[key]=1;
    else m[key]++;
}

void get_ys(long long digit)
{
    if (digit==1) return;
    for (long long i=2;i*i<=digit;i++) {
        if (digit%i==0) {
            add_m(i);
            get_ys(digit/i);
            return;
        }
    }
    // 是质数, 添加到质数map
    add_m(digit);
}



int main()
{
    long long n,digit,sum=1;
    cin >> n;
    for (long long i=1;i<=n;i++) {
        scanf("%d", &digit);
        // 对每个数得出可以由哪些质数相乘
        get_ys(digit);
    }
    map<long long , long long>::iterator iter;
    for (iter=m.begin();iter!=m.end();iter++) {
        long long sum1=1;
        long long k=iter->first;
        long long  v=iter->second;
        for (long long i=1;i<=v;i++) {
            long long res1=k;
            for (long long j=2;j<=i;j++) {
                res1=(res1*k)%1000000007;
            }
            sum1=(sum1+res1)%1000000007;
        }
        sum=(sum*sum1)%1000000007;
    }
    cout << sum;
    return 0;
}
