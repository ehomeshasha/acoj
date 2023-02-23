#include <bits/stdc++.h>


using namespace std;

/**
设有 n 个正整数（n≤20） ，将它们联接成一排，组成一个最大的多位整数。
例如：n=3 时，3 个整数 13，312，343 联接成的最大整数为：34331213
又如：n=4 时，4 个整数 7，13，4，246 联接成的最大整数为：7424613
输入格式:
第一行只有一个 n
第二行为 n 个整数
输出格式:
联接成的多位数
提示:
n<=20
每个整数不超过20位
样例 1 :
输入:
3
13 312 343
输出:
34331213
 */
bool msort(string a, string b)
{
    string c1=a+b,c2=b+a;
    return c1>c2;
}

int main()
{
    int N;
    string sr[20],result="";
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> sr[i];
    }
    sort(sr,sr+N,msort);
    // 贪心算法， 每次取字典序最大的
    for (int i=0;i<N;i++) {
        result+=sr[i];
    }
    cout << result;
    return 0;
}
