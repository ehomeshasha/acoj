#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1162
 */
struct Pos {
    int x,y;
} b[905][905];
int N,a[35][35],vis[35][35],b_idx,k,c[905];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};


void dfs(int x, int y)
{
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (vis[nx][ny]==0&&a[nx][ny]==0) {
            // 找到一个新的dfs连通分量，添加到数组
            vis[nx][ny]=1;
            b[b_idx][k++]=Pos{nx,ny};
            dfs(nx,ny);
        }
        if (a[nx][ny]==-1) c[b_idx]=1;
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
                b_idx++,k=0;
                vis[i][j]=1;
                b[b_idx][k++]=Pos{i,j};
                dfs(i,j);
            }
        }
    }

    for (int i=1;i<=b_idx;i++) {
        if (c[i]==1) continue; // 过滤掉边界的闭合圈
        for (int j=0;j<905;j++) {
            int x=b[i][j].x,y=b[i][j].y;
            if (x==0&&y==0) break;
            a[x][y]=2;
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
