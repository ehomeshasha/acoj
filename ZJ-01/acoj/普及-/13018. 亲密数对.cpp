#include <bits/stdc++.h>


using namespace std;

/**
给定两个不同的正整数a和b,如果a的因子和等于b,b的因子和等于a,且a≠b,
则a ，b为一对亲密数。给定正整数N，求 2~N 中的亲密数对。
输入格式:
第1行一个正整数N，1≤N≤2000
输出格式:
输出若干行，每行有两个用一个空格隔开的正整数,表示一对亲密数
样例 1 :
输入:
200
输出:
48 75
75 48
140 195
195 140
 */
int yzh(int n)
{
    int sum=0;
    for (int i=2;i<n;i++) {
        if (n%i==0) sum+=i;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    for (int i=2;i<=N;i++) {
        int qms=yzh(i);
        if (qms==i) continue;
        if (qms>=2&&qms<=N) {
            if (yzh(qms)==i) {
                printf("%d %d\n",i,qms);
            }
        }
    }

    return 0;
}
