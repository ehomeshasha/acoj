#include <bits/stdc++.h>


using namespace std;

/**
洛谷P1605迷宫

 */
int N,M,T,SX,SY,FX,FY,t1,t2,mg[10][10]={0},ans=0;
int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
void dfs(int x, int y)
{
    if (x==FX&&y==FY) {
        ans++;
        return;
    }
    for (int i=0;i<4;i++) {
        if (mg[x+dx[i]][y+dy[i]]==1) {
            mg[x+dx[i]][y+dy[i]]=0;
            dfs(x+dx[i],y+dy[i]);
            mg[x+dx[i]][y+dy[i]]=1;
        }
    }
}


int main()
{
    // 问有多少种迷宫方案， dfs
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;
    // 初始化迷宫
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            mg[i][j]=1;
        }
    }
    for (int i=0;i<T;i++) {
        cin >> t1 >> t2;
        mg[t1][t2]=0;
    }
    mg[SX][SY]=0; // 标记已访问，起点不能再次访问
    dfs(SX,SY);
    cout << ans;
    return 0;
}
