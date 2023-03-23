#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1219
 */
int N,grid[15][15],cnt=0,path[15],vis1[100],vis2[100],vis3[100];
// vis1列标记，vis2左下到右上，vis3左上到右下

void print_path()
{
    for (int i=0;i<N;i++) {
        printf("%d ",path[i]);
    }
    printf("\n");
}

void dfs(int i)
{
    if (i==N+1) {
        cnt++;
        if (cnt<=3) print_path();
        return;
    }
    for (int j=1;j<=N;j++) {
        if (vis1[j]==0&&vis2[i+j]==0&&vis3[i-j+N]==0) {
            path[i-1]=j,vis1[j]=1,vis2[i+j]=1,vis3[i-j+N]=1;
            dfs(i+1);
            path[i-1]=0,vis1[j]=0,vis2[i+j]=0,vis3[i-j+N]=0;
        }
    }
}


int main()
{
    scanf("%d",&N);
    dfs(1);
    printf("%d",cnt);
    return 0;
}
