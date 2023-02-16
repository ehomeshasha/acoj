#include <bits/stdc++.h>


using namespace std;

/**
12032. 解救小哈
  普及/提高-
题目详情
题解
测评详情
有一天，小哈一个去玩迷宫。但是方向感很不好的小哈很快就迷路了。小哼得知后便立即去解救无助的小哈。
 小哼当然是有备而来，已经弄清楚了迷宫地图，现在小哼要以最快速度去解救小哈。问题就此开始了……
迷宫由n行m列的单元格组成，每个单元格要么是空地，要么是障碍物。
 你的任务是帮助小哼找到一条从迷宫的起点到小哈所在位置的最短路径，注意障碍物是不能走的，当然也不能走到迷宫之外。n和m都小于等于100。
输入格式:
第一行有两个数N M。N表示迷宫的行，M表示迷宫的列。接来下来N行M列为迷宫，0表示空地，1表示障碍物。
 最后一行4个数，前两个数为迷宫入口的x和y坐标。后两个为小哈的x和y坐标。
输出格式:
一个整数表示小哼到小哈的最短步数。如果不能解救小哈则输出No Way!
样例 1 :
输入:
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
输出:
7
样例 2 :

输入:
3 3
1 1 1
0 1 0
0 1 0
2 1 3 3
输出:
No Way!
 */
struct MData {
    int x;
    int y;
    int step; // 当前步数
} mData[10005];
struct MQueue {
    int head;
    int tail;
    MData *datalist;
} mQueue{0,0,mData};
// 先进先出
// 入队
void enQueue(MData data)
{
    mQueue.datalist[mQueue.tail++]=data; // 队尾写入
}
// 出队
MData deQueue()
{
    return mQueue.datalist[mQueue.head++]; // 出队
}

int N,M,mg[105][105]={0},t,sx,sy,ex,ey; // 0为不能走，天然就有边界
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void bfs()
{
    while(mQueue.head!=mQueue.tail) {
        MData data=deQueue();
        int x=data.x,y=data.y,step=data.step;
        if (x==ex&&y==ey) { // 当找到终点，可以停止
            cout << step;
            return;
        }
        for (int i=0;i<4;i++) {
            if (mg[x+dx[i]][y+dy[i]]==1) {
                mg[x+dx[i]][y+dy[i]]=0;
                enQueue({x+dx[i],y+dy[i],step+1});
            }
        }
    }
    cout << "No Way!"; // 没有找到最优解
}

int main()
{
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cin >> t;
            mg[i][j]=1-t; // 实现0,1互换， 1为可通行， 0为不可通行
        }
    }
    cin >> sx >> sy >> ex >> ey;
    enQueue({sx,sy,0});
    bfs();
    return 0;
}
