#include <bits/stdc++.h>


using namespace std;

/**
你就要去购物了，现在你手上有N种不同面值的银币，每种银币有无限多个。为了方便购物，你希望带尽量少的银币，但要组合出1到X之间的任意值。
输入格式:
第一行两个数X、N，以下N各数，表示每种硬币的面值。
输出格式:
最少需要携带的银币个数，如果无解输出-1。
限制:
30%N<=3 X<=20
100% N<=10 X<=1000
样例 1 :
输入:
20 4
1 2 5 10
输出:
5

 1 1 1
 2 2 3
 3 不带 3
 4 2 5
 5 不带 5
 6 5 10
 7-10
 11 10 20


 */

int main()
{
    int X,N,yinbi[10],sum=0,cnt=0;
    cin >> X >> N;
    for (int i=0;i<N;i++) {
        cin >> yinbi[i];
    }
    sort(yinbi, yinbi+N);
    if (yinbi[0]!=1) {
        cout << -1;
        return 0;
    }
    for (int i=1;i<=X;i++) {
        if (i>sum) {
            for (int j=N-1;j>=0;j--) {
                if (i>=yinbi[j]) {
                    sum+=yinbi[j];
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
