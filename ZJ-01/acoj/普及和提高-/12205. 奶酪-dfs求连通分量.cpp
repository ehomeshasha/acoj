#include <bits/stdc++.h>


using namespace std;

/**
现有一块大奶酪，它的高度为 h，它的长度和宽度我们可以认为是无限大的，奶酪中间有许多半径相同的球形空洞。
我们可以在这块奶酪中建立空间坐标系，在坐标系中， 奶酪的下表面为z = 0，奶酪的上表面为z = h。
现在，奶酪的下表面有一只小老鼠 Jerry，它知道奶酪中所有空洞的球心所在的坐标。
如果两个空洞相切或是相交，则 Jerry 可以从其中一个空洞跑到另一个空洞，
特别地，如果一个空洞与下表面相切或是相交，Jerry 则可以从奶酪下表面跑进空洞；
如果一个空洞与上表面相切或是相交，Jerry 则可以从空洞跑到奶酪上表面。
位于奶酪下表面的 Jerry 想知道，在不破坏奶酪的情况下，能否利用已有的空洞跑到奶酪的上表面去?
空间内两点
P1(x1,y1,z1)
P2(x2,y2,z2)
的距离公式如下：
dist(P1,P2)=sqrt((x1-x2)^2+(y1-y2)^2+(z1-z2)^2)
测试数据1解析：第一组数据,由奶酪的剖面图可见：
第一个空洞在(0,0,0)与下表面相切，第二个空洞在(0,0,4)与上表面相切 ，两个空洞在(0,0,2)相切。输出：Yes
第二组数据,由奶酪的剖面图可见：两个空洞既不相交也不相切。输出：No
第三组数据,由奶酪的剖面图可见：两个空洞相交 且与上下表面相切或相交。输出：Yes
输入格式:
每个输入文件包含多组数据。  输入文件的第一行，包含一个正整数 T，代表该输入文件中所含的数据组数。
接下来是 T 组数据，
每组数据的格式如下：  第一行包含三个正整数 n，h 和 r，
两个数之间以一个空格分开，分别代表奶酪中空洞的数量，奶酪的高度和空洞的半径。
接下来的 n 行，每行包含三个整数 x、y、z，两个数之间以一个空格分开，表示空洞球心坐标为(x, y, z)。
输出格式:
输出文件包含 T 行，分别对应 T 组数据的答案，如果在第 i 组数据中，Jerry 能从下表面跑到上表面，则输出“Yes”，如果不能，则输出“No”（均不包含引号）。
限制:
对于 20%的数据，n = 1，1 ≤ h , r ≤ 10,000，坐标的绝对值不超过 10,000。
对于 40%的数据，1 ≤ n ≤ 8， 1 ≤ h , r ≤ 10,000，坐标的绝对值不超过 10,000。
对于 80%的数据，1  ≤ n  ≤ 1,000，1  ≤ h , r  ≤ 10,000，坐标的绝对值不超过 10,000。
对于 100%的数据，1 ≤ n ≤ 1,000，1 ≤ h , r ≤ 1,000,000,000，T ≤ 20，坐标的 绝对值不超过 1,000,000,000。
样例 1 :
输入:
3
2 4 1
0 0 1
0 0 3
2 5 1
0 0 1
0 0 4
2 5 2
0 0 2
2 0 4
输出:
Yes
No
Yes
 */
#define ll long long
struct Pos {
    ll x,y,z,j;
} pos_list[20][1000];
ll T;
bool vis[20][1000];
vector<Pos> vis_v[20];

bool check(Pos a, Pos b, ll r)
{
    ll dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    if (dist<=4*r*r) return true;
    return false;
}

void dfs(ll i, ll j, ll n, ll h, ll r, bool &ans)
{
    if (pos_list[i][j].z>=h-r) {
        ans=true;
        return;
    }
    for (ll k=0;k<vis_v[i].size();k++) {
        ll j1=vis_v[i][k].j;
        if (vis[i][j1]==0) {
            if(check(pos_list[i][j],pos_list[i][j1],r)) {
                vis[i][j1]=1;
                vector<Pos>::iterator iter;
                for (iter=vis_v[i].begin();iter!=vis_v[i].end();iter++) {
                    if (iter->j==j1) {
                        vis_v[i].erase(iter);
                        break;
                    }
                }
                dfs(i,j1,n,h,r,ans);
                if (ans) break;
            }
        }
    }
}


int main()
{
    scanf("%lld\n",&T);
    for (ll i=0;i<T;i++) { // T组数据
        ll n,h,r;
        scanf("%lld %lld %lld\n",&n,&h,&r);
        for (ll j=0;j<n;j++) {
            ll x,y,z;
            scanf("%lld %lld %lld\n",&x,&y,&z);
            pos_list[i][j]=Pos{x,y,z,j};
            vis_v[i].push_back(pos_list[i][j]);
        }
        // 开始计算每组数据，看老鼠是否能从下到上
        // 先按照z坐标排序，选择z<=r的n个点作为起点，遍历这些点求连通分量，
        // 如果求得的连通分量存在z>=h-r的，则可以跑出来，否则不能跑出来
        // sort(pos_list[i],pos_list[i]+n,msort);
        vector<Pos> down_v;
        for (ll j=0;j<n;j++) {
            if (pos_list[i][j].z <= r) down_v.push_back(pos_list[i][j]);
        }
        bool ans1=false;
        for (ll k=0;k<down_v.size();k++) {
            ll j=down_v[k].j;
            if (vis[i][j]==0) {
                vis[i][j]=1;
                vector<Pos>::iterator iter;
                for (iter=vis_v[i].begin();iter!=vis_v[i].end();iter++) {
                    if (iter->j==j) {
                        vis_v[i].erase(iter);
                        break;
                    }
                }
                dfs(i,j,n,h,r,ans1);
                if (ans1) break;
            }
        }
        if (ans1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
