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
// 非递归方式
int binary_search(int* a, int n, int target)
{
    int low=0,high=n,middle=0;
    while(low<=high) {
        if (low==high) return a[low];
        middle=(low+high)/2;
        if (target==a[middle]) return a[middle];
        else if (target<a[middle]) high=middle;
        else if (target>a[middle]) {
            if (low==middle) {
                for (int i=high-1;i>=low;i--) {
                    if (a[i]<target) return a[i];
                }
            }
            low=middle;
        }
    }
    return -1;
}

int main()
{
    int c[10005]={0},n,q,t,a[100005],a_idx=0;
    cin >> n >> q;
    for (int i=0;i<n;i++) {
        cin >> t;
        c[t]++;
    }
    for (int i=0;i<10005;i++) {
        if (c[i]>0) {
            a[a_idx++]=i;
        }
    }
    for (int i=0;i<q;i++) {
        cin >> t;
        if (c[t]>0) {
            printf("%d\n",t); // 直接能找到，返回
            continue;
        }
        // 二分查找
        int res=binary_search(a,a_idx,t);
        printf("%d\n",res);
    }
    return 0;
}
