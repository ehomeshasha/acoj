#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1443
 */
struct Pos {
    int x,y,depth;
};
int N,M,X,Y,a[410][410],vis[410][410];
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
queue<Pos> q;

void bfs()
{
    while (!q.empty()) {
        Pos p1=q.front();
        q.pop();
        int x=p1.x,y=p1.y,depth=p1.depth;
        for (int i=0;i<8;i++) {
            int nx=x+dx[i],ny=y+dy[i];
            // 未访问过且没有越界
            if (vis[nx][ny]==0&&a[nx][ny]!=-2) {
                vis[nx][ny]=1;
                a[nx][ny]=depth+1;
                Pos p2={nx,ny,depth+1};
                q.push(p2);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X >> Y;
    // 坐标统一偏移1, 因此X>=2,Y>=2,对0,1进行-1的边界化处理
    X+=1,Y+=1;
    // 初始化边界，最外两层-2
    for (int i=0;i<=N+3;i++) {
        a[i][0]=-2,a[i][1]=-2,a[i][M+2]=-2,a[i][M+3]=-2;
    }
    for (int j=0;j<=M+3;j++) {
        a[0][j]=-2,a[1][j]=-2,a[N+2][j]=-2,a[N+3][j]=-2;
    }
    // 初始化默认值，中间是-1，代表到不了
    for (int i=2;i<=N+1;i++) {
        for (int j=2;j<=M+1;j++) {
            a[i][j]=-1;
        }
    }
    q.push(Pos{X,Y,0});
    vis[X][Y]=1;
    a[X][Y]=0;
    bfs();
    for (int i=2;i<=N+1;i++) {
        for (int j=2;j<=M+1;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
