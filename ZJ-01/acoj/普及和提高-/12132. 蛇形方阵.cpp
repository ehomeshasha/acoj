#include <bits/stdc++.h>


using namespace std;

/**
在n*n方阵里填入1,2,...,n*n,要求填成蛇形。例如n=4时方阵为：
10	11	12	1
9	16	13	2
8	15	14	3
7	6	5	4
输入格式:
直接输入方阵的维数，即n的值。(n<=100)
输出格式:
输出结果是蛇形方阵。
样例 1 :
输入:
4
输出:
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4
 */

int grid[105][105]={0},N,vis[105][105]={0},n=1;
// 方向值 d 0向下， 1向左， 2向上， 3向右
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
void dfs(int x, int y, int d)
{
    // 搜寻下个走的点， 先判断是否要变换方向
    int nx=x+dx[d],ny=y+dy[d];
    if (vis[nx][ny]==1) {
        d=(d+1)%4; // 换方向
        nx=x+dx[d],ny=y+dy[d]; // 更新位置
    }
    if (vis[nx][ny]==0) {
        vis[nx][ny]=1;
        grid[nx][ny]=++n;
        dfs(nx,ny,d);
    }

}

int main()
{
    cin >> N;
    for (int i=0;i<=N+1;i++) {
        vis[0][i]=1;vis[i][0]=1;vis[N+1][i]=1;vis[i][N+1]=1;
    }
    vis[1][N]=n;
    grid[1][N]=1;
    dfs(1,N,0);
    // 打印
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
