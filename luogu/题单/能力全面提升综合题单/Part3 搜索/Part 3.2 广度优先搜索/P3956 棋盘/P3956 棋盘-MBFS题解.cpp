#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P3956
 */
const int INF=0x7f7f7f7f;
struct Pos {
    int x,y,v,gold;
};
int M,N,a[105][105],val[105][105],ans=INF;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1}; // 上、右、下、左
queue<Pos> q;

void bfs()
{
    while (!q.empty()) {
        Pos pos1=q.front();
        q.pop();
        int x=pos1.x,y=pos1.y,v=pos1.v,gold=pos1.gold;
        if (gold>ans) {
            // 剪枝， 如果这次搜索得到金币数已经大于已知的ans了， 那么必然不是最优解，直接结束
            continue;
        }
        if (x==M&&y==M) { // 到达终点, 继续后续搜索
            ans=min(ans,gold);
            continue;
        }
        for (int i=0;i<4;i++) {
            int nx=x+dx[i],ny=y+dy[i],gold_new;
            if (a[x][y]==0&&a[nx][ny]==0) continue; // 连续施法
            if (a[nx][ny]==-1) continue; // 越界
            // 可能4种情况怎么选，就是用记忆化搜索尽量搞小的
            if (a[nx][ny]>0) { // 下个格子有颜色，直接走不用施展魔法
                gold_new=gold+abs(v-a[nx][ny]);
                if (val[nx][ny]>gold_new) {
                    Pos p1={nx,ny,a[nx][ny],gold_new};
                    q.push(p1);
                    val[nx][ny]=gold_new; // 记忆当前选择的值
                }
            } else {
                // 如果下个格子为无颜色的，那么上个格子必须有颜色才能施展魔法,
                // 上面已经continue过了，这里可以直接施展魔法
                // 这里可以施展两种颜色，贪心的话就只有一种，设置为v的值
                if (val[nx][ny]>gold+2) {
                    Pos p1={nx,ny,a[x][y],gold+2};
                    q.push(p1);
                    val[nx][ny]=gold+2; // 记忆当前选择的值
                }
            }
        }
    }
}

int main()
{
    cin >> M >> N;
    for (int i=1;i<=N;i++) {
        int x,y,v;
        cin >> x >> y >> v;
        a[x][y]=v+1;
    }
    // 初始化边界
    for (int i=0;i<=M+1;i++) a[i][0]=-1,a[i][M+1]=-1;
    for (int j=0;j<=M+1;j++) a[0][j]=-1,a[M+1][j]=-1;
    // 初始化val
    memset(val,INF,sizeof(val));

    if (a[1][1]==0) {
        cout << -1;
        return 0;
    }

    // 左上角1,1
    val[1][1]=0;
    q.push(Pos{1,1,a[1][1],0});
    bfs();
    if (ans==INF) cout << -1;
    else cout << ans;
    return 0;
}
