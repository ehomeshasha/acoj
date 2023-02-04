#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
Fibonacci数列是1，1，2，3，5，8，13，21...以此类推。
你需要统计在Fibonacci的前n项中，‘1’出现了多少次。
输入格式:
一个整数n。
输出格式:
Fibonacci的前n项中，‘1’出现了多少次。
限制:
对于40%的数据，n<=10;
对于100%的数据，n<=40。
样例 1 :
输入:
7
输出:
3
样例 2 :
输入:
8
输出:
4

f(n)=f(n-1)+f(n-2)
 */
int find_cnt(int n, int n1) {
    int cnt=0;
    int r=1;
    while(r<n) {
        int n2=n%(r*10)/r;
        if (n1==n2) cnt++;
        r*=10;
    }
    return cnt;
}

int main()
{
    // 动态规划问题
    int n,sum,cnt=2;
    cin >> n;
    if (n==1||n==2) {
        cout << n << endl;
        return 0;
    }
    int a1=1;
    int a2=1;
    for (int i=3;i<=n;i++) {
        sum=a1+a2;
        cnt+=find_cnt(sum, 1);
        a1=a2;
        a2=sum;
    }
    cout << cnt << endl;

    return 0;
}
