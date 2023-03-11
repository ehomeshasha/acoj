#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1902

4 2
0 0
3 5
2 4
0 0

3
 */
const int INF=0x3f3f3f3f;
int N,M,grid[1005][1005]={0},ans,vis[1005][1005]={0};
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
struct Pos {
    int x,y;
};

// 二分+dfs也是正解 超时只能得20分,要注释vis[nx][ny]=0才能得AC
bool dfs(int x, int y, int number)
{
    if (x==N) return true;
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (grid[nx][ny]<=number&&vis[nx][ny]==0) { // 把边界设为INF，任何超出伤害和触碰边界的行为都会被拦截
            vis[nx][ny]=1;
            if (dfs(nx,ny,number)) return true; // 到终点了停止寻路
//            vis[nx][ny]=0;
        }
    }
    return false;
}

// 二分+bfs正解， 只需要找到一个解即可，可更快到达底部
bool bfs(int number)
{
    // 初始化vis矩阵和q
    queue<Pos> q;
    q.push({1,1});
    memset(vis, 0, sizeof(vis)); //重置数组
    vis[1][1]=1;
    while(!q.empty()) {
        Pos pos1=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int nx=pos1.x+dx[i],ny=pos1.y+dy[i];
            if (grid[nx][ny]<=number&&vis[nx][ny]==0) {
                vis[nx][ny]=1; // 标记被添加到队列
                if (nx==N) return true; // 到达终点
                Pos pos2=Pos{nx,ny};
                q.push(pos2);
            }
        }
    }
    return false;
}

bool judge(int number)
{
    // 在bfs搜索中找是否存在<=number的解，存在返回true
    // 剪枝条件：寻找的时候，每个点都不能大于number
    memset(vis, 0, sizeof(vis)); //重置数组
    vis[1][1]=1;
    return dfs(1,1,number);
//    return bfs(number);
}



int main()
{
    int l=INF,r=-INF;
    scanf("%d %d\n",&N,&M);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            scanf("%d", &grid[i][j]);
            l=min(grid[i][j],l);
            r=max(grid[i][j],r);
        }
    }
    // 边界设置无穷大
    for (int i=0;i<=N+1;i++) grid[i][0]=INF,grid[i][M+1]=INF;
    for (int j=0;j<=M+1;j++) grid[0][j]=INF,grid[N+1][j]=INF;

    // 打印
//    for (int i=0;i<=N+1;i++) {
//        for (int j=0;j<=M+1;j++) {
//            printf("%d ",grid[i][j]);
//        }
//        printf("\n");
//    }
    while(l<=r) {
        int mid=l+(r-l)/2;
        if (judge(mid)) { // 如果找到解，那么看还有没有更小的
            ans=mid,r=mid-1;
        } else { // 没有解说明mid太小了
            l=mid+1;
        }
    }
    printf("%d", ans);
    return 0;
}
