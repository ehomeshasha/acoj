#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1429

3
1 1
1 2
2 2

1.0000
 */
const int MAXN=200005,INF=0x3f3f3f3f;
struct Point {
    double x,y;
} p[MAXN];
int N,tmp[MAXN];
double ans;

bool cmp1(const Point &a, const Point &b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

bool cmp2(const int &a, const int &b)
{
    if (p[a].y==p[b].y) return p[a].x<p[b].x;
    return p[a].y<p[b].y;
}

double dist(Point &a, Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(int l, int r)
{
    if (l==r) return INF;
    if (l+1==r) return dist(p[l],p[r]); // 计算出距离的平方
    // l到N的中位数划分成S1，S2，以及中间部分三个子问题，然后递归求解
    int mid=l+(r-l)/2;
    double d1=solve(l,mid),d2=solve(mid+1,r);
    double d=min(d1,d2); // d为距离的平方
    // 求解中间部分K个点，平方要小于d
    int k=0;
    // 找出第三个问题子空间
    for (int i=l;i<=r;i++) {
        if (fabs(p[mid].x-p[i].x)<d) tmp[k++]=i; // 中间范围的所有点
    }
    // 遍历所有点，找比d更小距离
    sort(tmp,tmp+k,cmp2);
    for (int i=0;i<k;i++) {
        for (int j=i+1;j<k&&p[tmp[j]].y-p[tmp[i]].y<d;j++) {
            double dis1=dist(p[tmp[i]],p[tmp[j]]);
            if (dis1<d) d=dis1;
        }
    }
    return d;
}

int main()
{
    scanf("%lld",&N);
    for (int i=0;i<N;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
    sort(p,p+N,cmp1); // 按x排序
    double result=solve(0,N-1);
    ans=result; // 求解用的是平方，所以要开根号
    printf("%.4lf",ans);
    return 0;
}