#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P2678

难点就在于找出二分条件和去掉石头的条件，找到了条件用二分答案直接求解
 */


int main()
{
    int L,N,M,a[50005],ans;
    scanf("%d %d %d\n",&L,&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%d\n",&a[i]);
    }
    a[0]=0,a[N+1]=L; // 首尾两个点
    if (N==M) { // 如果全移走，直接输出L
        printf("%d", L);
        return 0;
    }
    // 二分答案
    int l=0,r=L;
    while(l<=r) {
//        for (int i=0;i<=N;i++) dis2[i]=dis[i];
        int mid=l+(r-l)/2,cnt=0,before=0;
        // 用mid去求解数量，比较求得的数量和M大小，然后去继续二分
        for (int i=1;i<=N+1;i++) {
            if (a[i]-before<mid) {
                // 移动一块石头，前一个石头位置不变
                cnt++;
            } else {
                before=a[i]; // 不移动石头，前一个石头位置更新
            }
        }
        if (cnt<=M) { // 二分答案太小，可以继续增加
            ans=mid;
            l=mid+1;
        } else { // 二分答案太大
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}
