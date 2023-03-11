#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1902

4 2
0 0
3 5
2 4
0 0

3
 */
const int MAXN=1005,MAXNN=MAXN*MAXN;
int N,M,grid[1005][1005]={0},ans,fa[MAXNN],idx=0;
struct Edge {
    int u,v,w;
} edge[MAXNN*2]; // 每个点可以连出两条边

// 编写一个函数，把二维坐标x,y转换成编号, NUMBER范围为1~N*M
int NUMBER(int x, int y) // x 1~N, y 1~M
{
    // x=1,y=1,n=1
    // x=1,y=2,n=2
    // x=1,y=3,n=3
    // x=2,y=1,n=4
    // x=2,y=2,n=5
    // x=2,y=3,n=6
    return M*(x-1)+y;
}

// 编写一个并查集
int ufind(int x)
{
    if (fa[x]==x) return x;
    fa[x]=ufind(fa[x]);
    return fa[x];
}

bool cmp(Edge &a, Edge &b)
{
    return a.w<b.w;
}

void kruskal()
{
    sort(edge, edge+idx, cmp); // 从小到大排序所有边
    int st=NUMBER(1,1), ed=NUMBER(N,M);
    for (int i=0;i<idx;i++) { // 枚举所有边
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        int x=ufind(u),y=ufind(v);
        if (x!=y) {
            ans=max(ans,w); // 更新最大边权
            fa[x]=fa[y]; // 两边连通
            if (ufind(st)==ufind(ed)) return;
        }
    }
}


int main()
{
    scanf("%d %d\n",&N,&M);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            scanf("%d", &grid[i][j]);
            int number=NUMBER(i,j);
            fa[number]=number; // 初始化并查集
        }
    }
    // 点权转换边权
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            // 连边
            int u=NUMBER(i,j);
            int v1=NUMBER(i,j+1); // 向右连边
            int v2=NUMBER(i+1,j); // 向下连边
            if (j+1<=M) edge[idx++]={u,v1,max(grid[i][j],grid[i][j+1])};
            if (i+1<=N) edge[idx++]={u,v2,max(grid[i][j],grid[i+1][j])};
        }
    }


    // 最小生成树kruskal算法
    kruskal();
    printf("%d",ans);
    return 0;
}
