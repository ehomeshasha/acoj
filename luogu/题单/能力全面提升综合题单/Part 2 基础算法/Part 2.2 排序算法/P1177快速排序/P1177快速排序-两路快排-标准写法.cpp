#include <bits/stdc++.h>


using namespace std;
int N,arr[100005];
//因为快排对于一些特殊的情况（例如序列原本就有序、有大量重复元素等等）会进行很多完全不必要的操作，耗费大量时间。
// 为此，我们基于上述普通快速排序算法一步步进行优化。
// 优化1. 随机枢轴
// 优化2. 交换相等的元素，使得相等元素左右两边均匀分配，避免TLE

int partition(int* a, int l, int r)
{
    // 随机枢轴
    int ran_idx=rand()%(r-l+1)+l;
    swap(a[ran_idx],a[l]);
    // 这里也可以用二分的枢轴, 因为极端情况就是完全有序的，每次都只能划分1个很慢，所以取中间的值划分刚好
//    int binary_idx=l+(r-l)/2;
//    swap(a[binary_idx],a[l]);
    int i=l+1,j=r,pivot=a[l];
    while(true) {
        while(i<=j&&a[i]<pivot) i++; // 先从左边开始找
        while(i<=j&&a[j]>pivot) j--;
        if (i>=j) break; // i和j相等，即两者相遇或者超过，跳出循环
        // 相等或者符合条件会停下
        swap(a[i++],a[j--]);
    }
    swap(a[l],a[i-1]); // 互换第一个元素和左区间最后一个元素
    return i-1;
}


void quick_sort(int* a, int l, int r)
{
    if (l>=r) return; // 只剩一个元素或者超出
    int mid=partition(a,l,r);
    quick_sort(a,l,mid-1);
    quick_sort(a,mid+1,r);
}

void start_quick_sort(int* a, int n)
{
    quick_sort(a,0,n-1);
}

int main()
{
    scanf("%d\n",&N);
    for (int i=0;i<N;i++) scanf("%d ",&arr[i]);
    start_quick_sort(arr, N);
    for (int i=0;i<N;i++) printf("%d ",arr[i]);
    return 0;
}
