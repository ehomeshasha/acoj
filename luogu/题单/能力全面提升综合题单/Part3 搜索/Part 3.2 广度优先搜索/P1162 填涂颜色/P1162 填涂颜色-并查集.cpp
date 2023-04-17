#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1162
 */
struct Pos {
    int x,y;
};
int N,a[35][35],vis[35][35];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int fx[905],invalid[905];

int ufind(int x)
{
    if (fx[x]==x) return x;
    fx[x]= ufind(fx[x]);
    return fx[x];
}

int zh(int x, int y)
{
    return (x-1)*N+y;
}

void dfs(int x, int y)
{
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (vis[nx][ny]==0&&a[nx][ny]==0) {
            // 并查集归类
            vis[nx][ny]=1;
            fx[zh(nx,ny)]=ufind(zh(x,y));
            dfs(nx,ny);
        }
        if (a[nx][ny]==-1) { // 能够触碰边界, 设置为无效
            invalid[ufind(zh(x,y))]=1;
        }
    }
}

int main()
{
    // 求连通分量
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> a[i][j];
        }
    }
    // 边界初始化-1
    for (int i=0;i<=N+1;i++) a[i][0]=-1,a[i][N+1]=-1;
    for (int i=0;i<=N+1;i++) a[0][i]=-1,a[N+1][i]=-1;

    // 初始化并查集
    for (int i=1;i<=904;i++) fx[i]=i;

//    // 打印
//    for (int i=0;i<=N+1;i++) {
//        for (int j=0;j<=N+1;j++) {
//            printf("%d",a[i][j]);
//        }
//        printf("\n");
//    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (vis[i][j]==0&&a[i][j]==0) {
                // b_idx代表第几个岛屿
//                b_idx++,k=0;
                vis[i][j]=1;
//                b[b_idx][k++]=Pos{i,j};
                dfs(i,j);
            }
        }
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (a[i][j]==0&&invalid[ufind(zh(i,j))]==0) {
                a[i][j]=2;
            }
        }
    }

    // 打印
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
