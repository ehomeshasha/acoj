#include <bits/stdc++.h>


using namespace std;

/**
有一天小明爱上看动画片“喜洋洋与灰太狼” ，但是小明的妈妈不喜欢让小明看动画片，因为小明一看动画片就不认真做作业，于是妈妈就给小明出了难题：
小明的姥姥家的后院养着一群羊，有一天姥姥由于疲劳睡着了，这时一群饿狼钻进了后院开始攻击羊群，
后院是由许多个方格构成的长方形区域，每个方格中用字符‘.’表示空地， ‘#’表示栅栏， ‘o’表示羊， ‘v’表示狼，羊和狼所在的格子都是空地。
如果从一个空地 A 沿着水平方向或垂直方向经过一系列的空地能够到达空地 B，则称空地 A 和空地 B 属于同一个羊圈。
对于能够逃离后院的空地我们认为它不属于任何一个羊圈。
当一个羊圈中羊的数量大于狼的数量时，它们会用它们的尖角顶死该羊圈中的狼，否则就将被狼吃掉，最后每个羊圈中只会剩下一种动物。
请你写程序帮小明计算一下， 战斗结束后所有羊圈中羊的总数和狼的总数？不然小明就再也不能看“喜羊羊与灰太狼了” 。
输入格式:
第一行包含两个用空格隔开的自然数 R 和 C，R 表示小明姥姥家家后院的行数，C 表示列数，接下来的 R 行每行包含 C 个字符，每个字符表示一个格子的情况。
输出格式:
仅一行，包含两个用一个空格隔开的整数，表示剩余羊的数量和狼的数量。
限制:
30%的数据，R,C<=30， 100%的数据，3<=R,C<=250
样例 1 :
输入:
9 12
.###.#####..
#.oo#...#v#.
#..o#.#.#.#.
#..##o#...#.
#.#v#o###.#.
#..#v#....#.
#...v#v####.
.####.#vv.o#
.......####.

.###.#####..
#111#333#3#.
#111#3#3#3#.
#11##3#333#.
#1#2#3###3#.
#11#1#3333#.
#1111#3####.
.####.#4444#
.......####.

3 2
0 1
2 2
1 2

3 2
2 2
0 1
0 0
1 2

输出:
3 5
 */
struct Pos {
    int x;
    int y;
    Pos(int x, int y): x(x),y(y) {}
};
queue<Pos> q;
int N,M,grid[255][255]={0},vis[255][255]={0},yq_idx=0,yang_total[63000]={0},lang_total[63000]={0},check[63000]={0}; // 每个羊圈中羊的数量和狼的数量
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

void bfs()
{
    while(!q.empty()) {
        Pos pos=q.front();
        q.pop();
        int x=pos.x,y=pos.y;
        // 从上下左右四个方向dfs，找出所有该羊圈的羊和狼的数量
        if (grid[x][y]==3) yang_total[yq_idx]++;
        else if (grid[x][y]==4) lang_total[yq_idx]++;
        // 继续搜寻
        for (int i=0;i<4;i++) {
            // 可以直接逃出去，不属于任何羊圈
            if (grid[x+dx[i]][y+dy[i]]==0) {
                check[yq_idx]=1; // check为1的数据需要过滤
                continue;
            }
            if (vis[x+dx[i]][y+dy[i]]==0&&grid[x+dx[i]][y+dy[i]]!=2) {
                vis[x+dx[i]][y+dy[i]]=1;
                Pos pos2=Pos(x+dx[i],y+dy[i]);
                q.push(pos2);
                bfs();
            }
        }
    }
}

int main()
{
    char t4[4],c;
    int t,ycnt=0,lcnt=0;
    cin >> N >> M;
    gets(t4);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            c=getchar();
            if (c=='.') t=1;
            else if (c=='#') t=2;
            else if (c=='o') t=3;
            else if (c=='v') t=4;
            grid[i][j]=t;
        }
        gets(t4);
    }
//    // 打印grid
//    for (int i=0;i<=N+1;i++) {
//        for (int j=0;j<=M+1;j++) {
//            printf("%d ",grid[i][j]);
//        }
//        printf("\n");
//    }
    // 求连通块
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            t=grid[i][j];
            if (t!=2&&t!=0) {
                if (i==1||i==N||j==1||j==M) continue; // 不属于任何一个羊圈
                if (vis[i][j]==0) {
                    // 发现一个新羊圈，对其求bfs
                    vis[i][j]=1;
                    Pos pos=Pos(i,j);
                    q.push(pos);
                    bfs();
                    yq_idx++;
                }
            }
        }
    }
    for (int i=0;i<yq_idx;i++) {
        if (check[i]==1) continue;
        if (yang_total[i]>lang_total[i]) ycnt+=yang_total[i];
        else lcnt+=lang_total[i];
    }
    cout << ycnt << " " << lcnt;
    return 0;
}
