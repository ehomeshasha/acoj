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
const int MAXN=1005,INF=0x3f3f3f3f;
struct Edge {
    int v;
    int w;
    Edge(int v, int w): v(v), w(w) {}
};
vector<Edge> v1[MAXN],v2[MAXN];
int N,M,dis[MAXN],total=0;

void spfa()
{
    memset(dis, INF, sizeof(dis));
    dis[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for (int i=0;i<v1[u].size();i++) {
            int v=v1[u][i].v;
            int w=v1[u][i].w;
            if (dis[u]+w<dis[v]) { // 如果走新目的地路径比原有的路径更短， 则选择走新目的地， 新目的地标记为1， 压入队列
                // 一直更新到已经无新目的地路径更短的情况， 当前路径就是最短路径
                dis[v]=dis[u]+w;
                q.push(v);
            }
        }
    }
}

void spfa2()
{
    memset(dis, INF, sizeof(dis));
    dis[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for (int i=0;i<v2[u].size();i++) {
            int v=v2[u][i].v;
            int w=v2[u][i].w;
            if (dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
                q.push(v);
            }
        }
    }
}

int main()
{
    // 单源最短路 dijkstra算法
    // 思路, 不断更新到某个点的最短路，中转点的值+后续路径值和当前值做比较取最小的
    cin >> N >> M;
    int u,v,w;
    for (int i=0;i<M;i++) {
        cin >> u >> v >> w;
        v1[u].push_back(Edge(v,w));
        v2[v].push_back(Edge(u,w));
    }
    spfa();
    for (int i=2;i<=N;i++) {
        total+=dis[i];
    }
    spfa2();
    for (int i=2;i<=N;i++) {
        total+=dis[i];
    }
    cout << total;
    return 0;
}
