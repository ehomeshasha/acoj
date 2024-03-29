#include <bits/stdc++.h>


using namespace std;

/**
有一个邮递员要送东西，邮局在结点 1。他总共要送 N-1 样东西，其目的地分别是 2～N。
 由于这个城市的交通比较繁忙，因此所有的道路都是单行的，共有 M 条道路，通过每条道路需要一定的时间。
 这个邮递员每次只能带一样东西。 求送完这 N-1 样东西并且最终回到邮局最少需要多少时间。
输入格式:
输入文件第一行包含一个正整数 N 和 M；
接下来 M 行， 每行三个正整数 U、 V、 W， 表示该条道路为从 U 到 V 的， 且通过这条道路
需要 W 的时间。满足 1≤U,V≤N≤1000,1≤W≤100000, 输入保证任意两点都能互相到达。
输出格式:
输出仅一行，包含一个整数，为最少需要的时间。
限制:
对于 30%的数据，满足 1≤N≤200。
对于 100%的数据，满足 1≤N≤1000,1≤M≤100000。
样例 1 :
输入:
5 10
2 3 5
1 5 5
3 5 6
1 2 8
1 3 8
5 3 4
4 1 8
4 5 3
3 5 9
5 4 2
输出:
83
 */

int main()
{
    // a点到b点最短路径， 用floyd算法打表
    // 打完之后遍历1到2~N和2~N到1的时间和
    int N,M,floyd[1005][1005]={0},t1,t2,t3,sum=0;
    scanf("%d %d\n",&N,&M);
    // 初始化表为无穷大
    for (int i=0;i<1005;i++) {
        for (int j=0;j<1005;j++) {
            if (i==j) floyd[i][j]=0;
            else floyd[i][j]=0x3f3f3f3f;
        }
    }
    // 初始化P0
    for (int i=1;i<=M;i++) {
        scanf("%d %d %d\n",&t1,&t2,&t3);
        if (floyd[t1][t2]>t3) floyd[t1][t2]=t3;
    }
    // 迭代求P1-PN
    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                // 求解最短路径
                if (i==j||i==k||j==k) continue; // 如果可以直达就不变
                // i->k k->j之和 和当前值做比较， 取小的那个
                floyd[i][j]=min(floyd[i][k]+floyd[k][j],floyd[i][j]);
            }
        }
    }
    // 打完之后遍历1到2~N和2~N到1的时间和
    for (int i=2;i<=N;i++) {
        // 1->i, i->1时间和
        sum+=floyd[1][i]+floyd[i][1];
    }
    cout << sum;
    return 0;
}
