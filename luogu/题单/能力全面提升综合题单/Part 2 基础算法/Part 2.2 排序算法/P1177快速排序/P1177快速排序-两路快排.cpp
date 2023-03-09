#include <bits/stdc++.h>


using namespace std;
int N,arr[100005];
struct Seq {
    int s,e;
};

//因为快排对于一些特殊的情况（例如序列原本就有序、有大量重复元素等等）会进行很多完全不必要的操作，耗费大量时间。
// 为此，我们基于上述普通快速排序算法一步步进行优化。
// 优化1. 随机枢轴
// 优化2. 找重复序列端点

Seq partition(int* a, int l, int r)
{
    // 随机枢轴
    int ran_idx=rand()%(r-l+1)+l;
    swap(a[ran_idx],a[l]);
    // 这里也可以用二分的枢轴, 因为极端情况就是完全有序的，每次都只能划分1个很慢，所以取中间的值划分刚好
//    int binary_idx=l+(r-l)/2;
//    swap(a[binary_idx],a[l]);
    int i=l,j=r,pivot=a[l];
    while(i<j) {
        while(i<j&&a[j]>=pivot) j--; // 先从右边开始找
        while(i<j&&a[i]<=pivot) i++;
        swap(a[i],i==j?a[l]:a[j]);
    }
    // 重复序列优化
    int s=i,e=i; // 向前向后遍历，遇到重复就-1或+1，最后得出重复序列的两端返回，作为下一次快排切分的两个端点
    while(a[s]==pivot) s--;
    while(a[e]==pivot) e++;
    return Seq{s,e};
}


void quick_sort(int* a, int l, int r)
{
    if (l>=r) return; // 只剩一个元素或者超出
    Seq seq=partition(a,l,r);
    quick_sort(a,l,seq.s);
    quick_sort(a,seq.e,r);
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
