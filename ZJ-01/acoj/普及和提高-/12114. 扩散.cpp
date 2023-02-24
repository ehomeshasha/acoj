#include <bits/stdc++.h>


using namespace std;

/**
一个点每过一个单位时间就会向4个方向扩散一个距离，如图所示：
两个点a、b连通，记作e(a,b),当且仅当a、b的扩散区域有公共部分。
连通块的定义是块内的任意两个点u、v都必定存在路径e(u,a0),e(a0,a1),...,e(ak,v)。
给定平面上的n个点，问最早什么时刻它们形成一个连通块。
一个点每过一个单位时间向4个方向扩散一个距离
输入格式:
第一行一个数n，以下n行，每行一个点坐标。
输出格式:
一个数，表示最早的时刻所有点形成联通块。
限制:
对于20%的数据，满足1≤N≤5；1≤X[i],Y[i]≤50;
对于100%的数据，满足1≤N≤50；1≤X[i],Y[i]≤10^9。
样例 1 :
输入:
2
0 0
5 5
输出:
5
说明:
样例 2 :
输入:
5
19 23
32 19
21 14
44 2
48 13
输出:
11
 */
struct Pos {
    int x,y;
};
struct Bian {
    int a,b,dis;
};
int N,bs_idx,group[50],ans=0;
Pos ps[50];
Bian bs[2500];
int mfind(int x)
{
    if (group[x]==x) return x;
    group[x]=mfind(group[x]); // 压缩路径优化
    return group[x];
}
bool msort(Bian a, Bian b)
{
    return a.dis<b.dis;
}

void kruskal()
{
    // 先排序，按照权值从小到大
    sort(bs,bs+bs_idx,msort);
    int bianshu=0;
    for (int i=0;i<N;i++) group[i]=i;
    for (int k=0;k<bs_idx&&bianshu<N-1;k++) { // k不超过最大边数量，选中边数不超过N-1
        int fa=mfind(bs[k].a),fb=mfind(bs[k].b);
        // 判断是否形成了一个环，没有成环则加边
        if (fa!=fb) {
            // 连边
            group[fb]=fa;
            bianshu++;
            // 取最长的那条边即为答案
//            if (ans<bs[k].dis) ans=bs[k].dis;
            ans = max(ans, bs[k].dis);
        }
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<i;j++) {
            int dis=abs(ps[i].x-ps[j].x)+abs(ps[i].y-ps[j].y);
            bs[bs_idx].a=i,bs[bs_idx].b=j,bs[bs_idx].dis=dis,bs_idx++;
        }
    } // 绘制出所有边
    // 最小生成树， 然后求最长的边
    kruskal();
    // 两点扩散需要的时间t=(abs(x-nx)+abs(y-ny))除以2向上取整
    cout << (ans+1)/2;
    return 0;
}
