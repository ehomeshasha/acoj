#include <bits/stdc++.h>


using namespace std;

/**
思路就是最简单的两两比对，按题目模拟
 */

int main()
{
    int N,a[500000],ans=0;
    scanf("%d\n",&N);
    for (int i=0;i<N;i++) {
        scanf("%d ",&a[i]);
    }
    for (int i=0;i<N-1;i++) {
        for (int j=i+1;j<N;j++) {
            if (a[i]>a[j]&&i<j) ans++;
        }
    }
    cout << ans;
    return 0;
}
