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
struct Pos {
    long long x,y,z;
} p[20][1000];
int T,fx[1000],f1[1000],f2[1000];

bool check(int i, int j, int k, long long r)
{
    Pos p1=p[i][j],p2=p[i][k];
    long long dist=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
    if (dist<=4*r*r) return true;
    return false;
}

int ufind(int x) {
    if (fx[x]==x) return x;
    fx[x]=ufind(fx[x]); // 路径缩短
    return fx[x];
}

int main()
{
    scanf("%d\n",&T);
    for (int i=0;i<T;i++) { // T组数据
        int n,h;
        long long r;
        scanf("%d %d %lld\n",&n,&h,&r);
        for (int j=0;j<n;j++) {
            long long x,y,z;
            scanf("%lld %lld %lld\n",&x,&y,&z);
            p[i][j]=Pos{x,y,z};
        }
        // 并查集初始化
        for (int j=0;j<n;j++) {
            fx[j]=j;
        }
        int tot1=0,tot2=0;
        // 遍历每个洞
        for (int j=0;j<n;j++) {
            if (p[i][j].z<=r) { // 存底洞
                f1[tot1++]=j;
            }
            if (p[i][j].z>=h-r) { // 存顶洞
                f2[tot2++]=j;
            }
            // 看这个洞之前的洞，如果能合并就合并
            for (int k=0;k<j;k++) {
                if (check(i,j,k,r)) {
                    int a1=ufind(j);
                    int a2=ufind(k);
                    if (a1!=a2) fx[a1]=a2;
                }
            }
        }
        // 合并完之后查找
        bool ans=false;
        for (int j=0;j<tot1;j++) { // 从底洞出发
            for (int k=0;k<tot2;k++) { // 遍历顶洞
                if (ufind(f1[j])==ufind(f2[k])) {
                    ans=true;
                    break;
                }
            }
            if (ans) break;
        }
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
