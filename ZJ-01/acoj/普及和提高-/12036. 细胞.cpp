#include <bits/stdc++.h>


using namespace std;

/**
一矩形阵列由数字0到9组成,数字1到9代表细胞,细胞的定义为沿细胞数字上下左右还是细胞数字则为同一细胞,求给定矩形阵列的细胞个数。如阵列:
02345000
67103456
05002045
60067100
00000089
有3个细胞
输入格式:
整数m,n(m行，n列)矩阵。
输出格式:
细胞的个数。
样例 1 :
输入:
4  10
0234500067
1034560500
2045600671
0000000089
输出:
4
 */
int N,M,cnt=0,grid[505][505]={0};
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

void dfs(int x, int y)
{
    for (int i=0;i<4;i++) {
        if (grid[x+dx[i]][y+dy[i]]!=0) {
            grid[x+dx[i]][y+dy[i]]=0;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main()
{
    char t2[4],t;
    cin >> N >> M;
    gets(t2);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            t=getchar();
            grid[i][j]=t-'0';
        }
        gets(t2);
    }

    // 打印地图
//    for (int i=1;i<=N;i++) {
//        for (int j=1;j<=M;j++) {
//            printf("%d",grid[i][j]);
//        }
//        printf("\n");
//    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (grid[i][j]!=0) {
                cnt++;
                // 当前的也置0
                grid[i][j]=0;
                dfs(i,j); // 递归去把同一细胞的grid置为0，这样在未来的遍历中不会++
            }
        }
    }
    cout << cnt;
    return 0;
}
