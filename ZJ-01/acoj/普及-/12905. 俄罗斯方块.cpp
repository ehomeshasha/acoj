#include <bits/stdc++.h>


using namespace std;

/**
首先把经典的俄罗斯方块游戏简化一下:方块有顺序地从屏幕顶端掉下至底部,当碰到障碍物或底部时将停下,同时变成新的障碍物。
游戏规则规定,只能在方块下落停止前决定下落时的横向位置,使这个方块变成障碍物后的高度最低,
且如果有几种横向位置使这个方块变成障碍物后的高度最低时,取最左边的横向位置下落。
输入格式:
第1行有2个整数,表示方块数n和屏幕宽度w,之间用1个空格分隔。
第2行~i+1行,每行1个整数,为第i个方块的边长a。
输出格式:
输出一个整数,表示最后障碍物的最高点高度。
提示:
对于100%的数据满足:1≤w≤20,1≤a≤w,1≤n≤100。
样例 1 :
输入:
3 5
2
1
3
输出:
4
 */

int get_maxH(int* a, int w) {
    int max_h=0;
    for (int i=0;i<w;i++) {
        if (a[i]>max_h) max_h=a[i];
    }
    return max_h;
}

int main()
{
    int n,w,ai,a[20]={0},s_h=0;
    cin >> n >> w;
    for (int i=0;i<n;i++) {
        cin >> ai;
        int max_h2=999999, s_j;
        for (int j=0;j<=w-ai;j++) { // 遍历的方式做多次尝试
            int maxh1=0;
            for (int k=j;k<j+ai;k++) { // 找出每次尝试最大的高度
                if (a[k]>maxh1) maxh1=a[k];
            }
            // 取所有尝试里面最小的高度
            if (maxh1<max_h2) {
                max_h2=maxh1;
                s_j=j;
            }
        }
        // 变更高度
        for (int j=s_j;j<s_j+ai;j++) a[j]=max_h2+ai;
    }
    cout << get_maxH(a,w);

    return 0;
}
