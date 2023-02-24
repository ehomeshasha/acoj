#include <bits/stdc++.h>


using namespace std;

/**
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。形式如下：
例如一个5行的蛇形矩阵如下：
1	3	4	10	11
2	5	9	12	19
6	8	13	18	20
7	14	17	21	24
15	16	22	23	25
输入格式:
一个正整数N。（1<=N<=100）
输出格式:
对于每一组数据，输出一个N行的蛇形矩阵。
样例 1 :
输入:
5
输出:
1 3 4 10 11
2 5 9 12 19
6 8 13 18 20
7 14 17 21 24
15 16 22 23 25

6
1 3 4 10 11 21
2 5 9 12 20 22
6 8 13 19 23 30
7 14 18 24 29 31
15 17 25 28 32 35
16 26 27 33 34 36
 */
// 路线是 向下1、右上、撞墙、向右1、左下、撞墙、向下1、 : mode=1
// 如果向下1撞墙， 则改变后续模式直至终止，向右1，右上、撞墙、向下1、左下、撞墙、向右1 : mode=2
// 如果向右1撞墙， 则改变后续模式直至终止，向下1，左下、撞墙、向右1、右上、撞墙、向下1 : mode=3
// 全部vis=1结束

const int INF=0x3f3f3f3f;
int grid[105][105],vis[105][105],N,mode=1,n=1,step=1;
// d代表循环的位置
int dxy[4][4][2]={
        {},
        {
                {1,0},{-1,1},{0,1},{1,-1},
        },
        {
                {0,1},{-1,1},{1,0},{1,-1}
        },
        {
                {1,0},{1,-1},{0,1},{-1,1}
        }
};
void dfs(int x, int y, int d)
{
    int nx=x+dxy[mode][d][0],ny=y+dxy[mode][d][1];
    if (nx==N+1&&N%2==1) {
        // 切换到模式2
        mode=2;
        d=0;
        step=1;
        nx=x+dxy[mode][d][0],ny=y+dxy[mode][d][1];
    }
    if (ny==N+1&&N%2==0) {
        // 切换到模式3
        mode=3;
        d=0;
        step=1;
        nx=x+dxy[mode][d][0],ny=y+dxy[mode][d][1];
    }
    if (step==0) {
        d=(d+1)%4;
        nx=x+dxy[mode][d][0],ny=y+dxy[mode][d][1];
        step=INF;
    } else if (vis[nx][ny]==1) {
        d=(d+1)%4;
        nx=x+dxy[mode][d][0],ny=y+dxy[mode][d][1];
        step=1;
    }
    if (vis[nx][ny]==0) {
        grid[nx][ny]=++n;
        vis[nx][ny]=1;
        step--;
        dfs(nx,ny,d);
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<=N+1;i++) {
        vis[0][i]=1,vis[i][0]=1,vis[N+1][i]=1,vis[i][N+1]=1;
    }
    grid[1][1]=n;
    vis[1][1]=1;
    dfs(1,1,0);
    // 打印
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
