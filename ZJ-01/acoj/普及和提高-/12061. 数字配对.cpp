#include <bits/stdc++.h>


using namespace std;

/**
对于给定的一列数字，数字个数为偶数，你需要解决如下问题：将给定的数列中的数字两两配对，
 这样每一对数字的和将形成一个新数列，对于不同的配对方法，新数列中的最大值也不同，寻找一个好的配对方法，使得新数列中的最大值最小。
输入格式:
第一行一个整数n(n<=10000)
第二行有n个正整数，为给定的一列数字
输出格式:
一个正整数，新数列中的最大值的最小值
样例 1 :
输入:
4
1 5 2 8
输出:
9
 */

int main()
{
    int n,sl[10005],nsl[5005],nsl_idx=0,max_v,min_v; // nsl为新数列，nsl_idx为下标&长度
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> sl[i];
    }
    sort(sl+1,sl+1+n);
    // 配对规则， 任意数列一定是先选取第一个和最后一个，得到的最大值最小
    while(nsl_idx!=n/2) {
        // 1...n
        // 2...n-1
        // 3...n-2
        nsl[nsl_idx]=sl[nsl_idx+1]+sl[n-nsl_idx];
        nsl_idx++;
    }
    sort(nsl,nsl+n/2);
    cout << nsl[n/2-1];
    return 0;
}
