#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
struct node
{
    long long x;
    long long y;
} arr[100005];
int cmp(node x,node y)
{
    return x.y<y.y;
}
int check(long long d)
{
    long long pos=-0x3f3f3f3f;int sum=0;
    for(int i=1;i<=m;)
    {
        while(pos+d>arr[i].y) {
            i++;
            if (i>m) { //没有区间了，不符合
                return 0;
            }
        }
        pos+=d;
        if(pos<arr[i].x) pos=arr[i].x;//要站在草上
        sum++;
        if (sum>=n) return 1; //有n个了，符合
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
        scanf("%lld%lld",&arr[i].x,&arr[i].y);
    sort(arr+1,arr+1+m,cmp);
    long long l=1,r=1e18;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(check(mid)) {
            ans=mid,l=mid+1;
        } else {
            r=mid-1;
        }
    }//二分模板
    printf("%lld",ans);
    return 0;
}
