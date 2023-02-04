#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/**
有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30，每个物品有一个体积（正整数）。
要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
输入格式:
1个整数，表示箱子容量
1个整数，表示有n个物品
接下来n行，分别表示这n个物品的各自体积
输出格式:
1个整数，表示箱子剩余空间。
样例 1 :
输入:
10
3
4
8
5
输出:
1
 */

int main()
{
    int V,n,dp[200005]={0},w[35]={0};
    cin >> V >> n;
    for (int i=1;i<=n;i++)
        cin >> w[i];

    // 打表, 滚动数组优化
    for (int i=1;i<=n;i++) {
        for (int j=V;j>=1;j--) {
            if (j>=w[i]) dp[j]=max(dp[j],w[i]+dp[j-w[i]]);
        }
    }
    cout << V-dp[V] << endl;

    return 0;
}
