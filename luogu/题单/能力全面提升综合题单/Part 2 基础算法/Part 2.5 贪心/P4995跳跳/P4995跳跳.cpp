#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P4995
 */

int main()
{
#define int long long
    int N,H[301],before=0,now,ans=0;
    cin >> N;
    for (int i=1;i<=N;i++) cin >> H[i];
    sort(H+1,H+1+N);
    for (int i=1;i<=N;i++) { // 跳N次
        // 第一次k=N
        // 第二次k=1
        // 第三次k=N-1
        // 第四次k=2，以此类推
        if (i%2==0) now=H[i/2];
        else now=H[N-i/2];
        ans+=(now-before)*(now-before);
        before=now;
    }
    cout << ans;
    return 0;
}
