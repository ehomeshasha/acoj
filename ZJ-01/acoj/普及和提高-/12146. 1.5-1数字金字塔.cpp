#include <bits/stdc++.h>


using namespace std;

/**
观察下面的数字金字塔。
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。
每一步可以走到左下方的点也可以到达右下方的点。
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输入格式:

第一个行包含 R(1<= R<=1000) ,表示行的数目。
后面每行为这个数字金字塔特定行包含的整数。
所有提供的整数是非负的且不大于100。
输出格式:

单独的一行,包含那个可能得到的最大的和。
样例 1 :

输入:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出:
30
 */
int N,grid[1005][1005],ans=0;


int main()
{
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=i;j++) {
            cin >> grid[i][j];
        }
    }
    // 打印
//    for (int i=0;i<=N+1;i++) {
//        for (int j=0;j<=i+1;j++) {
//            printf("%d ",grid[i][j]);
//        }
//        printf("\n");
//    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=i;j++) {
            grid[i][j]=max(grid[i-1][j-1],grid[i-1][j])+grid[i][j];
        }
    }
    // 打印
//    for (int i=1;i<=N;i++) {
//        for (int j=1;j<=i;j++) {
//            printf("%d ",grid[i][j]);
//        }
//        printf("\n");
//    }

    for (int j=1;j<=N;j++) {
        if (ans<grid[N][j]) ans=grid[N][j];
    }
    cout << ans;
    return 0;
}
