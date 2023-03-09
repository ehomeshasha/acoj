#include <bits/stdc++.h>


using namespace std;

/**
dust开着飞船在茫茫宇宙中航行……在穿越虫洞的时候，出现了一些外星飞船。由于虫洞的引力，dust只能向前开，并撞上这些外星飞船。
现在将dust的路线考虑为一个一维数轴，求dust会撞上多少个飞船？（即求这个数列中递增或相等数的个数。）
输入格式:
第一行输入 n（0<n<=1000），表示外星飞船数。
第二行 n 个整数（<=10^9），表示外星飞船的坐标。
输出格式:
一个整数，表示dust会撞上几个外星飞船。
样例 1 :

输入:
4
5 3 2 4
输出:
1
样例 2 :

输入:
3
1 1 1
输出:
3
样例 3 :

输入:
5
1 3 3 5 4
输出:
4
 */

int main()
{
    int N,maxn=0,ans=0;
    scanf("%d\n",&N);
    for (int i=0;i<N;i++) {
        int n;
        scanf("%d ",&n);
        if (maxn<=n) {
            maxn=n;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
