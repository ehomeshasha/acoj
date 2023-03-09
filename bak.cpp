#include <bits/stdc++.h>


using namespace std;

/**
在地平线上有n个建筑物。每个建筑物在地平线上可以看成一个下边界和地平线重合的矩形。
每个建筑物有三个描述（Li ,Ri,Hi）,分别表示该建筑物的左边界，右边界，高度。输出输出这些建筑物在地平线上投影的总面积。

输入格式:
输入文件horizon.in第一行包含一个整数n，表示有n个建筑物。
以下下n行，每行三个整数Li ,Ri,Hi。
输出格式:
输出这些建筑物在地平线上投影的总面积。
限制:
100%的数据满足：1<=n<=40,000
1 ≤ Li < Ri ≤ 1,000,000,000
1 ≤ Hi ≤ 1,000,000,000
样例 1 :
输入:
4
2 5 1
9 10 4
6 8 2
4 6 3
输出:
16
 */
#define int long long
struct Building {
    int l,r,h;
} B[40005];
int N,ans;

int cal_mj(const Building &a, const Building &b)
{
    // 两种碰撞情形，计算重合面积
    // case1全包含
    // a包含在b内
    int h=min(a.h,b.h);
    if (a.l>=b.l&&a.r<=b.r) return (a.r-a.l)*h;
    // b包含在a内 （把上面ab互换）
    if (b.l>=a.l&&b.r<=a.r) return (b.r-b.l)*h;
    // case2部分包含 // 因为已经把全包含关系return出去了，所以不需要考虑全包含情形
    // a在b左边
    if (a.l<=b.l&&a.r>=b.l) return (a.r-b.l)*h;
    // a在b右边 （把上面ab互换）
    if (b.l<=a.l&&b.r>=a.l) return (b.r-a.l)*h;
    return 0; // 不属于上面情形，不重合，返回0
}
bool msort(const Building &a, const Building &b)
{
    return a.l<b.l;
}
#undef int
int main()
{
#define int long long
    // 思路，两种碰撞情形，两两比较，得出两两重合面积，结果=总面积-两两重合面积，复杂度40000^2太高
    // 先依据l排序
    // 顺序遍历比较当前和下一个建筑，有两种情况
    // 情况1不重合，直接到下一步
    // 情况2重合，计算重合面积，ans减去
    // 继续比较下一轮直到结束
    scanf("%d\n",&N);
    for (int i=0;i<N;i++) {
        scanf("%d %d %d\n",&B[i].l,&B[i].r,&B[i].h);
    }
    // 先遍历所有建筑，加总面积
    for (int i=0;i<N;i++) ans+=(B[i].r-B[i].l)*B[i].h;
    sort(B,B+N,msort);
    for (int i=0;i<N;i++) {
        for (int j=i+1;j<N;j++) {
            Building a=B[i],b=B[j];
            // 情形1不重合
            if (a.r<b.l) { // 做剪枝
                break;
            }
            // 情形2重合
            ans-=cal_mj(a,b);
        }
    }
    cout << ans;
    return 0;
}
