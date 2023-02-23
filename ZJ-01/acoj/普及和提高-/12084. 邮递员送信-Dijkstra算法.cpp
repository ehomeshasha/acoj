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
3 5 9
1 2 8
1 3 8
5 3 4
4 1 8
4 5 3
3 5 6
5 4 2
输出:
83
 */
const int MAXN=1005,INF=0x3f3f3f3f;
int N,M,dis[MAXN],check[MAXN],total=0,graph[1005][1005],graph2[1005][1005]; // dis最短路径，last前驱节点，flag标记数组（实现类似队列pop操作）

int main()
{
    // 单源最短路 dijkstra算法
    // 思路, 不断更新到某个点的最短路，中转点的值+后续路径值和当前值做比较取最小的
    cin >> N >> M;
    int u,v,w;
    for (int i=0;i<M;i++) {
        cin >> u >> v >> w;
        if (graph[u][v]>0&&graph[u][v]<w) continue;
        graph[u][v]=w;
        if (graph2[v][u]>0&&graph2[v][u]<w) continue;
        graph2[v][u]=w;
    }
    memset(dis, INF, sizeof(dis));
    dis[1]=0;

    for (int i=1;i<=N;i++) { // 遍历N次
        int minv=INF,mini;
        for (int j=1;j<=N;j++) { // 求未标记的最小点开始处理
            if (dis[j]<minv&&check[j]==0) {
                minv=dis[j],mini=j;
            }
        }
        check[mini]=1; // 标记最小点
        for (int j=1;j<=N;j++) {
            if (graph[mini][j]>0) { // 如果和最小点有连边，则可以绕路
                if (minv+graph[mini][j]<dis[j]) { // 如果绕路更短则绕路，更新最短路径dis
                    dis[j]=minv+graph[mini][j];
                }
            }
        }
    }
    for (int i=2;i<=N;i++) {
        total+=dis[i];
    }

    // 反向图继续求解回来的路
    memset(dis, INF, sizeof(dis));
    memset(check, 0, sizeof(check));
    dis[1]=0;
    for (int i=1;i<=N;i++) { // 遍历N次
        int minv=INF,mini;
        for (int j=1;j<=N;j++) { // 求未标记的最小点开始处理
            if (dis[j]<minv&&check[j]==0) {
                minv=dis[j],mini=j;
            }
        }
        check[mini]=1; // 标记最小点
        for (int j=1;j<=N;j++) {
            if (graph2[mini][j]>0) {
                if (minv+graph2[mini][j]<dis[j]) { // 如果绕路更短则绕路
                    dis[j]=minv+graph2[mini][j];
                }
            }
        }
    }
    for (int i=2;i<=N;i++) {
        total+=dis[i];
    }
    cout << total;
    return 0;
}
