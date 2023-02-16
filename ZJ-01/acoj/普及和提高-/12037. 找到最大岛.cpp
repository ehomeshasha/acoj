#include <bits/stdc++.h>


using namespace std;

/**
小哼通过秘密方法得到一张不完整的钓鱼岛航拍地图。钓鱼岛由一个主岛和一些附属岛屿组成，小哼决定去钓鱼岛探险。
 下面这个10*10的二维矩阵就是钓鱼岛的航拍地图。图中数字表示海拔，0表示海洋，1~9都表示陆地。现在需要计算出最大岛的面积（即有多少个格子）。
输入格式:
第一行2个整数，整数表示n行m列。
接下来n行，每行m列，整数之间用空格隔开表示地图。
输出格式:
输出一个正整数，即最大岛的面积
限制:
n<=100
m<=100
样例 1 :
输入:
10 10
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
输出:
38
 */
struct Daoyu {
    int mj;
};
int N,M,grid[105][105]={0},max_mj=0;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void dfs(int x, int y, Daoyu &daoyu)
{
    for (int i=0;i<4;i++) {
        if (grid[x+dx[i]][y+dy[i]]!=0) {
            daoyu.mj++;
            grid[x+dx[i]][y+dy[i]]=0;
            dfs(x+dx[i],y+dy[i],daoyu);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cin >> grid[i][j];
        }
    }
    // 打印地图
//    for (int i=1;i<=N;i++) {
//        for (int j=1;j<=M;j++) {
//            printf("%d ",grid[i][j]);
//        }
//        printf("\n");
//    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (grid[i][j]!=0) {
                // 发现一块新大陆
                grid[i][j]=0;
                Daoyu daoyu{1};
                dfs(i,j,daoyu);
                if (max_mj<daoyu.mj) max_mj=daoyu.mj;
            }
        }
    }
    cout << max_mj;
    return 0;
}
