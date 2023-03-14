#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1094
 */


int main()
{
//    int W,N,a[30005],ans=0;
//    cin >> W >> N;
//    int r=N-1;
//    for (int i=0;i<N;i++) cin >> a[i];
//    sort(a,a+N);
//    // 从大往小遍历，找出<W的数组
//    for (int i=N-1;i>=0;i--) {
//        if (a[i]<W) {
//            r=i; // [0-i]数组，i+1个元素，剩余N-(i+1)个元素只能单独一组
//            ans+=N-1-i;
//            break;
//        }
//    }
//    for (int i=0;i<=r;i++) {
//        bool found=false;
//        for (int j=r;j>i;j--) { // 从r到i+1去寻找是否存在数
//            if (a[j]+a[i]<=W) { // 存在可以合并的数
//                found=true;
//                ans++; // 两个i，j纪念品分成一组
//                ans+=r-j; // r到j之间的单个独立1组
//                r=j-1; // 合并数前1位置为右边界
//                break;
//            }
//        }
//        if (!found) { // 那从i到r之间的数都成不了对了，就不用后续寻找了，直接每个数自成1组
//            ans+=r-i+1;
//            break;
//        }
//    }
//    更简洁的解法
    int W,N,a[30005],ans=0;
    cin >> W >> N;
    for (int i=1;i<=N;i++) cin >> a[i];
    sort(a+1,a+1+N);
    int l=1,r=N;
    while(l<=r) {
        if (a[l]+a[r]<=W) { // 可以两个组成一组
            l++,r--,ans++;
        } else {
            r--,ans++;
        }
    }
    cout << ans;
    return 0;
}
