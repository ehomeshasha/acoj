#include <bits/stdc++.h>


using namespace std;

/**
输入n ，计算S ＝1！＋2！＋3！＋…＋n ！的末6位（不含前导0）。n ≤10^6 ，n ！表示前n 个正整数之积。
输入格式:
输入一行，一个正整数n，n<=1000,000。
输出格式:
输出一行，为阶乘之和，结果只包含末尾的6位整数，不包含前导0。
样例 1 :
输入:
10
输出:
37913
 */

int main()
{
    long long n,a[1000005],sum=1;
    cin >> n;
    a[1]=1;
    for (int i=2;i<=n;i++) {
        a[i]=(a[i-1]*i)%1000000;
        sum=(sum+a[i])%1000000;
    }
    cout << sum;
    return 0;
}
