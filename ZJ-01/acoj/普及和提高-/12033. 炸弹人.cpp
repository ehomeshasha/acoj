#include <bits/stdc++.h>


using namespace std;

/**
小哼最近爱上了“炸弹人”游戏。你还记得在小霸王游戏机上的炸弹人吗？用放置炸弹的方法来消灭敌人。
 需将画面上的敌人全部消灭后，并找到隐藏在墙里的暗门才能过关。
现在有一个特殊的关卡如下。你只有一枚炸弹，但是这枚炸弹威力超强（杀伤距离超长，可以消灭杀伤范围内所有的敌人）。
 请问在哪里放置炸弹才可以消灭最多的敌人呢。
我们先将这个地图模型化。墙用 # 表示。这里有两种墙，一种是可以被炸掉的，另外一种是不能被炸掉的。
 但是由于现在只有一枚炸弹，所以都用 # 表示，炸弹是不能穿墙的。敌人用 G 表示，空地用 . 表示，当然炸弹只能放在空地上。
输入格式:
第一行2个整数为n m 表示迷宫的行和列，接下来的n行m列为地图。
1<=n,m<=50
输出格式:

输出做最多可以消灭的敌人数
样例 1 :

输入:
13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
输出:
8
 */
struct MPos {
    int x;
    int y;
    int kill;
};
int grid[55][55]={0};
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

void dfs(int x, int y, int fx, MPos &pos)
{
    if (grid[x][y]==0) return; // 撞到墙了
    if (grid[x][y]==2) pos.kill++; // 敌人+1
    dfs(x+dx[fx],y+dy[fx],fx,pos);
}

int main()
{
    int n,m,max_kill=0;
    char t,t2[4];
    map<char,int> mp={{'#',0},{'.',1},{'G',2}};
    vector<MPos> v1;
    cin >> n >> m;
    gets(t2);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            t=getchar();
            grid[i][j]=mp[t];
            if (t=='.') v1.push_back(MPos{i,j});
        }
        gets(t2);
    }

    for (int i=0;i<v1.size();i++) {
        // 遍历每个空地， 该空地放置炸弹可以炸死的敌人数
        int x=v1[i].x,y=v1[i].y;
        v1[i].kill=0;
        for(int j=0;j<4;j++) { // 四个方向搜索
            dfs(x,y,j,v1[i]);
        }
        if (max_kill<v1[i].kill) max_kill=v1[i].kill;
    }
    cout << max_kill;
    return 0;
}
