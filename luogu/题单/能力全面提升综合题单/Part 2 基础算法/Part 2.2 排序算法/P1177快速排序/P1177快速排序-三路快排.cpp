#include <bits/stdc++.h>


using namespace std;
int N,arr[100005];
//因为快排对于一些特殊的情况（例如序列原本就有序、有大量重复元素等等）会进行很多完全不必要的操作，耗费大量时间。
// 为此，我们基于上述普通快速排序算法一步步进行优化。
// 优化1. 随机枢轴
// 优化2. 三路快排

struct Seq {
    int s,e;
};
Seq partition(int* a, int l, int r)
{
    // 随机枢轴
    int ran_idx=rand()%(r-l+1)+l;
    swap(a[ran_idx],a[l]);
    // 三路快排
    int i=l+1,j=r,k=l+1,pivot=a[l]; // i是左区间最后一个元素，j是右区间第一个元素，k是当前元素
    while(k<=j) {
        if (a[k]<pivot) { // 抛到左区间，和左区间最后一个元素互换
            swap(a[k],a[i]);
            i++,k++; // 这里左边多了一个元素，所以当前元素被往右挤了一个位置，k需要++
        } else if (a[k]>pivot) { // 抛到右区间，和右区间第一个元素互换
            swap(a[k],a[j]);
            j--; // 抛到右区间，左区间数量没变，当前元素不用++
        } else { // 如果相等，那么因为该元素就处于中间区间，所以左右区间不用动，继续往右移动，增加中间区间的数量即可
            k++;
        }
    }
    // 全部结束后，需要把第一个基准元素和左区间最后一个元素互换, 因为while里面互换后i有++且初始i就是l+1的，所以这里要把1减掉
    swap(a[l],a[i-1]);
    // 全部完毕后，基准元素在i-1位置，左区间为[l,i-2],右区间为[j+1,r];
    return Seq{i-2,j+1};
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
