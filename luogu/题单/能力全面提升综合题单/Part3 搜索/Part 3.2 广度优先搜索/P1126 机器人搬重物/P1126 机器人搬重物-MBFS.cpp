#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1126
 */
const int INF=0x3f3f3f3f;
struct Pos {
    int x, y, d, v;
    vector<Pos> vec;
} st,ed;
int N,M,a[55][55]={0},val[55][55]={0};
// 方向打表, E=0,S=1,W=2,N=3
map<char,int> dm = {{'E',0},{'S',1},{'W',2},{'N',3}};
char st_dir;
int st_d;
int dx[3]={0,1,1},dy[3]={1,1,0};
// E=0,S=1,W=2,N=3
int dxy[4][3][2]={
        {
                {0,1},{0,2},{0,3}
        }, // 东边，x不变，y增加
        {
                {1,0},{2,0},{3,0}
        }, // 南边，x增加，y不变
        {
                {0,-1},{0,-2},{0,-3}
        }, // 西边，x不变，y减少
        {
                {-1,0},{-2,0},{-3,0}
        }, // 北边，x减少，y不变
};
queue<Pos> q;
int ans=INF;

bool check_stand(int x, int y)
{
    // 以左上角格子为顶点检测是否可以站立机器人
    if (a[x][y]==1) return false;
    for (int i=0;i<3;i++) {
        if (a[x+dx[i]][y+dy[i]]==1) return false;
    }
    return true;
}


bool check_stand_all(int x, int y, int dir, int step) {
    for (int i=0;i<=step;i++) {
        int nx=x+dxy[dir][i][0],ny=y+dxy[dir][i][1];
        if (!check_stand(nx,ny)) return false;
    }
    return true;
}



vector<Pos> clone_arr(vector<Pos> &source) {
    vector<Pos> target;
    for (int i=0;i<source.size();i++) target.push_back(source[i]);
    return target;
}

int cal_turn_time(int d1, int d2)
{
    if (abs(d1-d2)==2) return 2; // 刚好相反，需要时间为2
    if (d1==d2) return 0; // 相同，需要时间为0
    return 1; // 其他情况转1次即可，需要时间Wie1
}

void bfs()
{
    while (!q.empty()) {
        Pos p1=q.front();
        q.pop();
        int x=p1.x,y=p1.y,d=p1.d,v=p1.v;
        // 如果到达终点，直接结束
        if (x==ed.x&&y==ed.y) {
            ans=min(ans,v);
            continue;
        }
        // 剪枝，如果v大于ans直接中止
        if (v>ans) continue;

        for (int dir=0;dir<4;dir++) { // dir为4个方向, E=0,S=1,W=2,N=3
            for (int step=0;step<3;step++) { // step为步数，走1-3步
                // 剪枝
                // 1.机器人从起始xy到nxny之间的连续格子存在不可站立情况
                int nx=x+dxy[dir][step][0],ny=y+dxy[dir][step][1];
                if (!check_stand_all(x,y,dir,step)) {
                    continue;
                }
                // 花费的时间计算
                // 1. 计算转身可能时间 2.加上走路的时间 +1 3.加上已经用的时间
                int v1=cal_turn_time(dir,d)+1+v;
                if (val[nx][ny]>v1) { // 如果v1更小，说明是更优的解， 那就选择v1解法
                    Pos p2={nx,ny,dir,v1};
                    Pos p3={nx-3,ny-3,dir,v1};
                    p2.vec=clone_arr(p1.vec);
                    p2.vec.push_back(p3);
                    q.push(p2);
                    val[nx][ny]=v1;
                }
            }
        }
    }
}


int main()
{
    cin >> N >> M;
    // 使用memset()函数初始化二维数组时要千万小心：
    // 1.二维整型数组利用memset()函数初始化时，只能初始化为0或者-1，否则二维整型数组的值将为随机数。
    // 2.二维char数组利用memset()函数初始化时不受限制，可初始化为任意字符。
    // 初始化边界， 1为障碍
    // 初始化val记忆数组为INF
    // 因为是二维数组因此不能用memset，要手动初始化
    for (int i=0;i<55;i++)
        for (int j=0;j<55;j++) a[i][j]=1,val[i][j]=INF;

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cin >> a[i+3][j+3]; // xy都偏移3好计算
        }
    }

    cin >> st.x >> st.y >> ed.x >> ed.y >> st_dir;
    st.x+=3,st.y+=3,ed.x+=3,ed.y+=3; // xy都偏移3， 不影响最终结果
    st_d=dm[st_dir]; // 初始方向

    // 机器人起点或终点所在4个格子必须都为0， 否则输出-1
    if (!check_stand(st.x, st.y)||!check_stand(ed.x, ed.y)) {
        cout << -1;
        return 0;
    }

    Pos stp=Pos{st.x,st.y,st_d,0};
    Pos stp1=Pos{st.x-3,st.y-3,st_d,0};
    stp.vec.push_back(stp1);
    q.push(stp);
    val[st.x][st.y]=0; // 不会走回头路了， 因为已经最小为0了
    bfs();
    if (ans==INF) cout << -1;
    else cout << ans;

    return 0;
}
