#include <iostream>

using namespace std;

//因为快排对于一些特殊的情况（例如序列原本就有序、有大量重复元素等等）会进行很多完全不必要的操作，耗费大量时间。
// 为此，我们基于上述普通快速排序算法一步步进行优化。
// 优化1. 随机枢轴
// 优化2. 找重复序列端点
struct Seq {
    int s,e;
};
Seq partition(int* a, int l, int r)
{
    int i=l,j=r;
    // 随机枢轴
    int ran_idx=rand()%(r-l+1)+l;
    swap(a[ran_idx],a[l]);
    int bn=a[l];
    while(i<j) {
        while(i<j&&a[j]>=bn) j--;
        while(i<j&&a[i]<=bn) i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[l]);
    // 重复序列优化
    int s=i,e=i; // 向前向后遍历，遇到重复就-1或+1，最后得出重复序列的两端返回，作为下一次快排切分的两个端点
    while(a[s]==bn) s--;
    while(a[e]==bn) e++;
    return Seq{s,e};
}


void quick_sort(int* a, int l, int r)
{
    if (l>=r) return; // 只剩一个元素或者超出
    Seq seq=partition(a,l,r);
    quick_sort(a,l,seq.s);
    quick_sort(a,seq.e,r);
}


int main() {

    /**
     * 快速排序-4
     * 带有比较的稳定排序，通过比较基准数分成左右两部分
     * 思路
     * 两路快排，交换
     * 针对有序数列和重复数列有两个优化点
     * 1. 随机枢轴
     * 2. 找重复序列端点，替代mid
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