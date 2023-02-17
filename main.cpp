#include <bits/stdc++.h>


using namespace std;

/**
你就要去购物了，现在你手上有N种不同面值的银币，每种银币有无限多个。为了方便购物，你希望带尽量少的银币，但要组合出1到X之间的任意值。
 y=a1*b1+a2*b2+a3*b3+a4*b4 能写成这种形式，且b1+b2+b3+b4和最小 y要取[1,X]都有解
输入格式:
第一行两个数X、N，以下N各数，表示每种硬币的面值。
输出格式:
最少需要携带的银币个数，如果无解输出-1。
限制:
30% N<=3 X<=20
100% N<=10 X<=1000
样例 1 :
输入:
20 4
1 2 5 10
输出:
5
 */


int main()
{
    int X,N,yinbi[11],yb_count[11]={0},tmp_count[11]={0},max_cnt=0; // yb_count为打表用的计数器，tmp_count为临时计数器
    cin >> X >> N;
    for (int i=0;i<N;i++) {
        cin >> yinbi[i];
    }
    sort(yinbi,yinbi+N);
    if (yinbi[0]!=1) {
        cout << "-1";
        return 0;
    }
    // 对于1~X优先使用最大的币结算
    for (int i=1;i<=X;i++) {
        // 清空N个面值的计数器
        for (int j=N-1;j>=0;j--) {
            tmp_count[j]=0;
        }
        // 对于每个面值求解
        int t=i;
        for (int j=N-1;j>=0;j--) {
            if (yinbi[j]>X) continue; // 如果银币都超过最大要求数，则跳过， 不需要拿这个银币
            // 贪心，优先拿最大的
            tmp_count[j]=t/yinbi[j]; // 银币计数增加
            t=t%yinbi[j];
            if (t==0) break; // 说明已经结算完
        }
        if (t!=0) { // 如果没有除尽，说明无解
            cout << "-1";
            return 0;
        }
        for (int j=N-1;j>=0;j--) {
            if (tmp_count[j]>yb_count[j]) yb_count[j]=tmp_count[j];
        }
    }
    for (int j=N-1;j>=0;j--) {
        max_cnt+=yb_count[j];
    }

    cout << max_cnt;
    return 0;
}
