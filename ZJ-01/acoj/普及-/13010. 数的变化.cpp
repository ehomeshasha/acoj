#include <bits/stdc++.h>


using namespace std;

/**
给出两个整数a和b,每次操作可以a+1和a*2,问至少进行多少次操作可以使得a=b。
输入格式:
一行两个整数a和b,之间用一个空格隔开
输出格式:
一行一个整数ans,表示至少进行多少次操作可以使得a=b.
限制:
对于30%的数据：1<=a<=b<=100
对于60%的数据：1<=a<=b<=10^6
对于100%的数据：1<=a<=b<=10^9
样例 1 :
输入:
2 10
输出:
3
 */

int main()
{
    long long a,b,cnt=0,shang,yushu;
    cin >> a >> b;
    for (;;) {
        shang=b/2;
        yushu=b%2;
        if (a==shang) {
            cnt+=yushu+1;
            break;
        } else if (a>shang) {
            cnt+=b-a;
            break;
        } else {
            b=shang;
            cnt+=yushu+1;
        }
    }
    cout << cnt;

    return 0;
}
