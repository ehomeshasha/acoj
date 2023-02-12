#include <bits/stdc++.h>


using namespace std;

/**
一棵有n个顶点的树（树就是无向无环图，可以保证任意两点之前有且只有一条路），现在有n个询问，
请输出每个询问的两点之前路过的所有点。
输入格式:
第一行 n,表示n个顶点
接下来n-1行每行为a b，表示a到b有一条边
第n行为一个整数k，表示接下来有k行表示有个询问，每条询问为p q
(1≤n≤10^5,k<=10)
输出格式:
对于每条询问p q，请输出p到q的路径中的所有点
限制:
1≤n≤10^5,k<=10
样例 1 :
输入:
7
1 2
1 3
2 4
2 5
3 6
3 7
3
1 7
5 7
4 3
输出:
1 3 7
5 2 1 3 7
4 2 1 3
样例 2 :
输入:
5
1 2
1 4
2 3
3 5
1
1 5
输出:
1 2 3 5
 */
//struct Node {
//    int d;
//    vector<Node> child;
//};
vector<int> data[100001];

bool bfs(int p, int q, int last)
{
    vector<int> v=data[p];
    for (int i=0;i<v.size();i++) {
        if (v[i]==last) continue; // 不走回头路
        if (v[i]==q) return true;
        bool res=bfs(v[i],q, p);
        if (res) {
            printf("%d ",v[i]);
            return true;
        }
    }
    return false;
}

int main()
{
    int n,a,b,k,p,q;
    cin >> n;
    for (int i=0;i<n-1;i++) {
        scanf("%d %d\n", &a, &b);
        data[a].push_back(b);
        data[b].push_back(a);
    }
    cin >> k;
    for (int i=0;i<k;i++) {
        cin >> p >> q;
        printf("%d ",p);
        bfs(q,p,0); // bfs求最优解
        printf("%d\n",q);
    }

    return 0;
}
