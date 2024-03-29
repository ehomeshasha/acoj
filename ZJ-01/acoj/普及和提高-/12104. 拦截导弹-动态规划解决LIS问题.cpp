#include <bits/stdc++.h>


using namespace std;

/**
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。
 但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
 某天， 雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截 所有的导弹。
 输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）： 计算这套系统最多能拦截多少导弹；
输入格式:

第一行为一个整数n，表示接下来有n个整数 （1<=n<=100）
第二行,包括若干以空格分隔的正整数,表示来袭的导弹的高度.
输出格式:

只有一个正整数,表示最多能拦截的导弹数;
样例 1 :

输入:
8
389 207 155 300 299 170 158 65
输出:
6

LIS问题
 389 -> 389
 207 -> 389 207
 155 -> 389 155 -> 389 207 155
 300 -> 389 300
 299 -> 389 299 -> 389 300 299
 170 -> 389 170 -> 389 207 170 ->
 158
 65

9
1 9 3 2 4 8 7 5 6
1 1

dp[i]
 1. dp[i]
 2. dp[i-1]

dp[0]=1,0
dp[1]=2,1
dp[2]=dp[1]+1=3,2
dp[3]=dp[2]=3,2
dp[4]=dp[3]=3,2
dp[5]=dp[4]+1
8
0 1 2 3 4 5 6 7
8 5 2 7 6 4 3 1
1 2 3 2 3 4


 */

int main()
{
    int N,dd[105],dp[105],ans=1;
    cin >> N;
    if (N==1) {
        cout << 1;
        return 0;
    }
    for (int i=1;i<=N;i++) {
        cin >> dd[i];
    }
    // 动态规划 解LIS问题， 最长上升子序列
    for (int i=1;i<=N;i++) dp[i]=1;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<i;j++) {
            // dp[i], dp[j]+1 选最优
            if (dd[i]<=dd[j]) dp[i]=max(dp[i],dp[j]+1);
        } // 得到i为结束点的最长子序列，取最大
        ans=max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}
