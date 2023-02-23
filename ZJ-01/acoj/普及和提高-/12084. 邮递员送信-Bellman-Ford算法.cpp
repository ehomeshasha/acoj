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
struct Edge {
    int v;
    int w;
    Edge(int v, int w): v(v), w(w) {}
};
vector<Edge> v1[MAXN],v2[MAXN];
int N,M,dis[MAXN],total=0; // dis最短路径，last前驱节点，flag标记数组（实现类似队列pop操作）

int main()
{
    // 单源最短路 Bellman-Ford算法
    // 思路
    // 一次性松弛所有边， 松弛N次
    cin >> N >> M;
    int u,v,w;
    for (int i=0;i<M;i++) {
        cin >> u >> v >> w;
        v1[u].push_back(Edge(v,w));
        v2[v].push_back(Edge(u,w));
    }
    memset(dis, INF, sizeof(dis));
    dis[1]=0;
    for (int i=1;i<=N;i++) { // 遍历N次，每次对所有边进行松弛操作
        bool flag=false;
        for (int j=1;j<=N;j++) {
            if (dis[j]==INF) continue;
            for (int k=0;k<v1[j].size();k++) {
                Edge ed=v1[j][k];
                if (dis[j]+ed.w<dis[ed.v]) {
                    dis[ed.v]=dis[j]+ed.w;
                    flag=true;
                }
            }
        }
        if (!flag) break;
    }
    for (int i=2;i<=N;i++) {
        total+=dis[i];
    }

    // 反向图继续求解回来的路
    memset(dis, INF, sizeof(dis));
    dis[1]=0;
    for (int i=1;i<=N;i++) { // 遍历N次，每次对所有边进行松弛操作
        bool flag=false;
        for (int j=1;j<=N;j++) {
            if (dis[j]==INF) continue;
            for (int k=0;k<v2[j].size();k++) {
                Edge ed=v2[j][k];
                if (dis[j]+ed.w<dis[ed.v]) {
                    dis[ed.v]=dis[j]+ed.w;
                    flag=true;
                }
            }
        }
        if (!flag) break;
    }
    for (int i=2;i<=N;i++) {
        total+=dis[i];
    }
    cout << total;
    return 0;
}
