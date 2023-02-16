#include <bits/stdc++.h>


using namespace std;

/**
小哼最近爱上了“炸弹人”游戏。你还记得在小霸王游戏机上的炸弹人吗？用放置炸弹的方法来消灭敌人。需将画面上的敌人全部消灭后，并找到隐藏在墙里的暗门才能过关。
现在有一个特殊的关卡如下。你只有一枚炸弹，但是这枚炸弹威力超强（杀伤距离超长，可以消灭杀伤范围内所有的敌人）。请问在哪里放置炸弹才可以消灭最多的敌人呢。
我们先将这个地图模型化。墙用 # 表示。这里有两种墙，一种是可以被炸掉的，另外一种是不能被炸掉的。但是由于现在只有一枚炸弹，所以都用 # 表示，炸弹是不能穿墙的。敌人用 G 表示，空地用 . 表示，当然炸弹只能放在空地上。
必须由小人能够走到的地方才能放置炸弹。比如下面这个例子小人默认站在(3,3)这个位置。请问放在何处最多可以消灭多个敌人。
输入格式:
第一行4个整数为n m x y，分别n和m表示迷宫的行和列，x和y表示小人的起始坐标（从0行0列开始计算），接下来的n行m列为地图。
1<=n,m<=50
输出格式:
最多可以消灭的敌人数。
样例 1 :
输入:
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
输出:
10
说明:
将炸弹放置在(7,11)处，最多可以消灭10个敌人。
 */
struct Pos {
    int x;
    int y;
    int kill;
};
// 还是最外层加一圈#，防止越界跑出去, 所有坐标比原坐标+1表示， 例如原来题目中的(3,3)，就为(4,4)
int grid[55][55]={0},visit[55][55]={0},max_kill=0;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

void dfs2(int x, int y, int fx, Pos &pos)
{
    if (grid[x][y]==0) return; // 撞墙
    if (grid[x][y]==2) pos.kill++; // 消灭敌人+1
    dfs2(x+dx[fx],y+dy[fx],fx,pos);
}

void cal_kill(int x, int y)
{
    Pos pos1{x,y,0};
    // 对4个方向求dfs
    for (int i=0;i<4;i++) {
        dfs2(x,y,i,pos1);
    }
    if (max_kill<pos1.kill) max_kill=pos1.kill;
}

void dfs(int x, int y)
{
    // 对每个点求炸弹放置可以炸死的敌人数，加入v1列表
    cal_kill(x,y);
//    max_kill++;
    for (int i=0;i<4;i++) { // 4个方向都去dfs可能求解
        if (visit[x+dx[i]][y+dy[i]]==1) {
            visit[x+dx[i]][y+dy[i]]=0;
            dfs(x+dx[i],y+dy[i]);
//            visit[x+dx[i]][y+dy[i]]=1; 不回溯，不走回头路
        }
    }
}

int main()
{
    int n,m,sx,sy;
    char t,t2[4];
    map<char,int> mp={{'#',0},{'.',1},{'G',2}};
    map<char,int> mp_visit={{'#',0},{'.',1},{'G',0}}; // 墙和敌人不可通过，空地可通过
    cin >> n >> m >> sx >> sy;
    gets(t2);
    sx++;sy++; // 比原坐标+1表示， 最终结果-1表示
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            t=getchar();
            grid[i][j]=mp[t];
            visit[i][j]=mp_visit[t];
        }
        gets(t2);
    } // 初始化地图完成

//    for (int i=1;i<=n;i++) {
//        for (int j=1;j<=m;j++) {
//            printf("%d ",visit[i][j]);
//        }
//        printf("\n");
//    } // 打印地图

    // 从起点出发，走dfs，最终回到终点， 每个格子都会走到1次，敌人和墙是不能走的，
    // 然后对每个格子4个方向dfs求解炸弹数， 找到最多的那个点
    visit[sx][sy]=0;
    dfs(sx,sy);
    cout << max_kill;
    return 0;
}
