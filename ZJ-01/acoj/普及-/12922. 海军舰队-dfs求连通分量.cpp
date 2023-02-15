#include <bits/stdc++.h>


using namespace std;

/**
在疫情期间，为了防止疫情的扩散，海军舰队得处于高度戒备，并且每只船之间需要间隔一定的距离，因此如何布置船只的位置，成了海军指挥官的难题，请你来帮助他。
在一个方形的盘上，放置了固定数量和形状的船只，每只船却不能碰到其它的船。在本题中，我们认为船是方形的，所有的船只都是由图形组成的方形。
求出该棋盘上放置的船只的总数。
输入格式:
第一行为两个整数 n 和 m，用空格隔开，分别表示游戏棋盘的行数和列数。
接下来 n行，每行 m 个字符，为 '#' 或 '.' 。 '# '表示船只的一部分，'.' 表示水。
输出格式:
一行一个字符串，如果船的位置放得正确（即棋盘上只存在相互之间不能接触的方形，如果两个 # 号上下相邻或左右相邻却分属两艘不同的船只，则称这两艘船相互接触了）。
 就输出 There are S ships.，S 表示船只的数量。否则输出 Bad placement.。
限制:
对于 100% 的数据，1≤n,m≤1000
样例 1 :
输入:
6 8
.....#.#
##.....#
##.....#
.......#
#......#
#..#...#
输出:
There are 5 ships.
样例 2 :
输入:
6 8
.....###
##.....#
##.....#
.......#
#......#
#..#...#
输出:
Bad placement.
 */
// dfs求连通分量，先不用并查集
int n,m,grid[1005][1005],visit[1005][1005],ship_cnt=0;
char c,t[2];

void dfs(int i, int j) {
    visit[i][j]=1;
    // 求四个相邻方向是否连通
    // 向上
    if (i>=1&&grid[i-1][j]==1&&visit[i-1][j]==0) {
        dfs(i-1,j);
    }
    // 向右
    if (j<=m-2&&grid[i][j+1]==1&&visit[i][j+1]==0) {
        dfs(i,j+1);
    }
    // 向下
    if (i<=n-2&&grid[i+1][j]==1&&visit[i+1][j]==0) {
        dfs(i+1,j);
    }
    // 向左
    if (j>=1&&grid[i][j-1]==1&&visit[i][j-1]==0) {
        dfs(i,j-1);
    }
}


bool judge()
{
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (i<=n-2&&j<=m-2) {
                // ##
                // #.
                if (grid[i][j]==1&&grid[i][j+1]==1&&grid[i+1][j]==1&&grid[i+1][j+1]==0) return false;
                // ##
                // .#
                if (grid[i][j]==1&&grid[i][j+1]==1&&grid[i+1][j]==0&&grid[i+1][j+1]==1) return false;
                // #.
                // ##
                if (grid[i][j]==1&&grid[i][j+1]==0&&grid[i+1][j]==1&&grid[i+1][j+1]==1) return false;
                // .#
                // ##
                if (grid[i][j]==0&&grid[i][j+1]==1&&grid[i+1][j]==1&&grid[i+1][j+1]==1) return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    gets(t);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            c=getchar();
            if (c=='#') grid[i][j]=1;
            else grid[i][j]=0;
        }
        gets(t);
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j]==1&&visit[i][j]==0) {
                ship_cnt++;
                dfs(i,j);
            }
        }
    }

    // 判断是否都是正方形，都满足的话输出， 有一个不满足则不输出
    bool res=judge();
    if (res) printf("There are %d ships.",ship_cnt);
    else printf("Bad placement.");


    return 0;
}
