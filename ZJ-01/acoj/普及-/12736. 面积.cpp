#include <bits/stdc++.h>


using namespace std;

/**
Alice 有一个边长为 a 的正方形，Bob 有一个长宽分别为 b,c 的矩形，请你告诉他们俩谁的图形面积更大。
输入格式:
仅一行三个正整数 a,b,c
输出格式:
输出仅一行一个字符串，若正方形面积大则输出 Alice，否则输出 Bob。
限制:
对于 30% 的数据，1≤a,b,c≤100，b=c；
对于 80% 的数据，1≤a,b,c≤10^4；
对于 100% 的数据，11≤a,b,c≤10^9 。
样例 1 :
输入:
5 4 6
输出:
Alice
说明:
正方形面积为 2525，矩形面积为 2424。
样例 2 :
输入:
7 5 10
输出:
Bob
说明:
正方形面积为 4949，矩形面积为 5050。
 */

int main()
{
    long long a,b,c;
    cin >> a >> b >> c;
    if (a*a>b*c) {
        printf("Alice");
    } else {
        printf("Bob");
    }
    return 0;
}
