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
struct Line {
    int s;
    int e;
    int w;
};
vector<Line> v1[1005],v2[1005];

Line mfind(vector<Line> lines, int s, int e)
{
    for (int i=0;i<lines.size();i++) {
        if (lines[i].s==s&&lines[i].e==e) return lines[i];
    }
    return {0,0,0};
}

void mdelete(vector<Line> &lines, int s, int e)
{
    vector<Line>::iterator iter;
    for (iter=lines.begin();iter!=lines.end();iter++) {
        if (iter->s==s&&iter->e==e) {
            lines.erase(iter);
            break;
        }
    }
}

struct Data {
    int step;
    int n;
};
queue<Data> q1,q2;
int vis1[1005]={0},vis2[1005]={0},dis1[1005]={0},dis2[1005]={0};

void bfs1()
{
    while(!q1.empty()) {
        Data d1=q1.front();
        q1.pop();
        if (vis1[d1.n]==0) {
            vis1[d1.n]=1;
            for (int i=0;i<v1[d1.n].size();i++) {
                dis1[v1[d1.n][i].e]=min(dis1[v1[d1.n][i].e], dis1[d1.n]+v1[d1.n][i].w); // 当前点的距离=上个点的距离+此次权值之和和目前值取更小的
                Data d2=Data{d1.step+1,v1[d1.n][i].e};
                q1.push(d2);
            }
        }
    }
}

void bfs2()
{
    while(!q2.empty()) {
        Data d1=q2.front();
        q2.pop();
        if (vis2[d1.n]==0) {
            vis2[d1.n]=1;
            for (int i=0;i<v2[d1.n].size();i++) {
                dis2[v2[d1.n][i].e]=min(dis2[v2[d1.n][i].e], dis2[d1.n]+v2[d1.n][i].w); // 当前点的距离=上个点的距离+此次权值之和和目前值取更小的
                Data d2=Data{d1.step+1,v2[d1.n][i].e};
                q2.push(d2);
            }
        }
    }
}

int main()
{
    // 单源最短路 dijkstra算法
    // 思路, 不断更新到某个点的最短路，中转点的值+后续路径值和当前值做比较取最小的
    int N,M,total=0,t1,t2,t3,INF=0x3f3f3f3f;
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> t1 >> t2 >> t3;
        Line l1=mfind(v1[t1], t1, t2);
        if (l1.w!=0&&l1.w<t3) continue; // 如果已有的比当前的小，什么都不做
        else if (l1.w!=0) mdelete(v1[t1], t1, t2);
        v1[t1].push_back({t1,t2,t3});
        Line l2=mfind(v2[t2], t2, t1);
        if (l2.w!=0&&l2.w<t3) continue; // 如果已有的比当前的小，什么都不做
        else if (l2.w!=0) mdelete(v2[t2], t2, t1);
        v2[t2].push_back({t2,t1,t3});
    }

    // 初始化dis1，dis2
    for (int i=2;i<=N;i++) {
        dis1[i]=INF;
        dis2[i]=INF;
    }

    Data d1=Data{1,1};
    vis1[1]=0;
    dis1[1]=0;
    q1.push(d1);
    bfs1();
    for (int i=0;i<1005;i++) {
        total+=dis1[i];
    }

    Data d2=Data{1,1};
    vis2[1]=0;
    dis2[1]=0;
    q2.push(d2);
    bfs2();
    for (int i=0;i<1005;i++) {
        total+=dis2[i];
    }



    cout << total;
    return 0;
}
