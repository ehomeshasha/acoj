#include <bits/stdc++.h>
using namespace std;

/**
 * 洛谷P3912
题目描述
 求1,2,...,N中素数的个数
输入格式
 一行一个整数N
输出格式
 一行一个整数，表示素数的个数
输入样例
 10
输出样例
 4
说明/提示
 对于40%的数据，1<=N<=10^6
 对于80%的数据，1<=N<=10^7
 对于100%的数据，1<=N<=10^8
 */
bool is_prime(int n)
{
    if (n==2) return true;
//    for (int i=2;i<n;i++) {
    int t=sqrt(n);
    for (int i=2;i<=t;i++) {
        // 可以改良成i*i<n，也可以写成 i<=sqrt(n), 因为如果存在大于根号n且能被整除n的数a,
        // 那么b=n/a一定是一个小于根号n且也能被n整数的数，而由循环可知小于根号n且能被n整数的数已经判断过return了，
        // 所以不需要遍历到n而是到根号n即可
        if (n%i==0) return false;
    }
    return true;
}


int main()
{
    int n,cnt=0;
    cin >> n;
    for (int i=2;i<=n;i++) {
        if (is_prime(i)) cnt++;
    }
    cout << cnt;
    return 0;
}
