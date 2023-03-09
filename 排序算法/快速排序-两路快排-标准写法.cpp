#include <iostream>

using namespace std;

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
        while(i<=j&&a[i]<pivot) i++;
        while(i<=j&&a[j]>pivot) j--; // 先从右边开始找
        if (i>=j) break; // i和j相等，即两者相遇或者超过，跳出循环
        // 相等或者符合条件会停下
        swap(a[i++],a[j--]);
    }
    swap(a[l],a[j]);
    return j;
}


void quick_sort(int* a, int l, int r)
{
    if (l>=r) return; // 只剩一个元素或者超出
    int mid=partition(a,l,r);
    quick_sort(a,l,mid-1);
    quick_sort(a,mid+1,r);
}


int main() {

    /**
     * 快速排序-4
     * 带有比较的稳定排序，通过比较基准数分成左右两部分
     * 思路
     * 两路快排，交换
     * 针对有序数列和重复数列有两个优化点
     * 1. 随机枢轴
     * 2. 三路快排
     * 相对于归并排序属于原地排序，不需要临时数组，非稳定排序
     * 适用范围：
     * 时间复杂度： O(nlogn)
     */

    int a[6] = {1,7,5,3,9,6};
    int len = sizeof(a) / sizeof(a[0]);
    quick_sort(a,0,len-1);

    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}