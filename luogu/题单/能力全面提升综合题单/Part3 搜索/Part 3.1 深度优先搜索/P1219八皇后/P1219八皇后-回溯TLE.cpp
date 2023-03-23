#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1219
 */
struct Pos {
    int x,y;
} p[225];

int N,grid[15][15],cnt=0,path[15],vis[15][15],p_idx=0,path2[15];
//int dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1}; // 只判断斜下方的旗子
int dx[4]={1,1},dy[4]={1,-1}; // 只判断斜下方的旗子

void biaoji(int x, int y, int type)
{
    if (type==1) { // 打标记
//        if (vis[x][y]==0) { // 当前点标记
//            p[p_idx++]=Pos{x,y};
//            vis[x][y]=1;
//        }
        for (int i=1;i<=N;i++) { // 竖列标记
            if (vis[i][y]==0) {
                p[p_idx++]=Pos{i,y};
                vis[i][y]=1;
            }
        }
//        for (int j=1;j<=N;j++) { // 横行标记
//            if (vis[x][j]==0) {
//                p[p_idx++]=Pos{x,j};
//                vis[x][j]=1;
//            }
//        }
        for (int k=0;k<2;k++) { // 斜行标记
            int nx=x+dx[k],ny=y+dy[k];
            while (grid[nx][ny]!=-1) {
                if (vis[nx][ny]==0) {
                    p[p_idx++]=Pos{nx,ny};
                    vis[nx][ny]=1;
                }
                nx+=dx[k],ny+=dy[k];
            }
        }
    } else {
        // 回退之前的操作
        int p_idx2=path2[x-1];
        for (int i=p_idx2;i<p_idx;i++) {
            int nx=p[i].x,ny=p[i].y;
            vis[nx][ny]=0;
        }
        p_idx=p_idx2; // 索引回退
    }
}


void print_path()
{
    for (int i=0;i<N;i++) {
        printf("%d ",path[i]);
    }
    printf("\n");
}

void dfs(int i)
{
    if (i==N+1) {
        cnt++;
        if (cnt<=3) print_path();
        return;
    }
    for (int j=1;j<=N;j++) {
        if (vis[i][j]==0) {
            path[i-1]=j;
            path2[i-1]=p_idx;
            biaoji(i,j,1);
            dfs(i+1);
            biaoji(i,j,0);
            path[i-1]=0;
            path2[i-1]=0;
        }
    }
}


int main()
{
    scanf("%d",&N);
    // 初始化边界为-1
    for (int i=0;i<=N+1;i++) grid[0][i]=-1,grid[N+1][i]=-1;
    for (int i=0;i<=N+1;i++) grid[i][0]=-1,grid[i][N+1]=-1;
    dfs(1);
    printf("%d",cnt);
    return 0;
}
