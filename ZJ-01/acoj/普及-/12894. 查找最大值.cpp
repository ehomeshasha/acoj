#include <bits/stdc++.h>


using namespace std;

/**
给定n个数整数的序列a，有q个询问，对于每个询问x，求该序列中小于等于x的数中最大的一个。
输入格式:
第一行两个数n和q，分贝表示序列个数和询问个数。
第2行n个数，为序列的n个数。
接下来q行，每行一个数x。
输出格式:
输出q行，输出满足小于等于x的最大数。
限制:
1<n<=100000
1<q<=100000
0<=a[i],x<=10000
样例 1 :
输入:
4 3
2 1 4 6
4
3
5
输出:
4
2
4
 */

int main()
{
    int c[10005]={0},n,q,t;
    cin >> n >> q;
    for (int i=0;i<n;i++) {
        cin >> t;
        c[t]++;
    }
    for (int i=0;i<q;i++) {
        cin >> t;
        for (int j=t;j>=0;j--) {
            if (c[j]>0) {
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}
