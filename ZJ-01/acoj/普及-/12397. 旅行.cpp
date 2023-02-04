#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;


int n,m,b1,b2;
vector<int> e[5005];
pair<int,int> edge[5005];
int du,dv,visit[5005];
vector<int> path(5005,5005);
int cnt=0,better=0;

/**

 */
bool dfs(int city) {
    if (better==0) {
        if (city>path[cnt]) return true;
        if (city<path[cnt]) better=1;
    }
    visit[city]=1;
    path[cnt++]=city;
    for (int i=0;i<e[city].size();i++) {
        int city2=e[city][i];
        if (visit[city2]==1) continue;
        if (du==city&&dv==city2) continue;
        if (dv==city&&du==city2) continue;
        if (dfs(city2)) return true; // 短路，直接弹到第一层
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i=1;i<=m;i++) {
        cin >> b1 >> b2;
        e[b1].push_back(b2);
        e[b2].push_back(b1);
        edge[i]={b1, b2};
    }
    for (int i=1;i<=n;i++)
        sort(e[i].begin(),e[i].end());

    if (n==m+1) dfs(1);
    else {
        // 需要暴力断边
        for (int i=1;i<=m;i++) {
            du=edge[i].first;
            dv=edge[i].second;
            memset(visit,0,sizeof(visit));
            cnt=better=0;
            dfs(1);
        }
    }
    for (int i=0;i<n;i++)
        printf("%d ", path[i]);

    return 0;
}
