#include <bits/stdc++.h>
using namespace std;

// 以大顶堆堆化为例
// 维护堆的性质
void heapify(int arr[], int n, int i)
{
    int largest=i,lson=i*2+1,rson=i*2+2; // 父节点(i-1)/2,左孩子i*2+1,右孩子i*2+2 - 完全二叉树性质
    if (lson<n&&arr[largest]<arr[lson]) largest=lson;
    if (rson<n&&arr[largest]<arr[rson]) largest=rson;
    if (largest!=i) {
        // 交换
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}




void heapSort(int arr[], int n) {
    // 建堆, 从数组最后一个元素的父节点开始 最后一个元素i=n-1, 父节点为 (n-1-1)/2=n/2-1
    for (int i=n/2-1;i>=0;i--) {
        heapify(arr,n,i);
    }
    // 排序
    for (int i=n-1;i>0;i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}



int main()
{

    /**
     * 堆排序: 每次取最大或者最小
     * 大顶堆 升序
     * 小顶堆 降序
     *
     * 堆化
     * i的父节点(i-1)/2
     * i的左孩子 i*2+1
     * i的右孩子 i*2+2
     *
     * 1. 建堆 - 从最后一个元素父节点开始（一定是叶子节点的父节点）
     * 2. 排序 - 交换顶点和最后一个元素，再维护堆的性质， 从n-1开始
     *
     * 特点：排序靠节点的下沉，局部有序情况下非常快， 只需要移动很少的节点
     * 遇到大体有序，需要将某个数插入有序数组里面情况， 可以考虑堆排序
     *

     适用范围： 原地排序，不稳定
     时间复杂度： O(nlogn)
     */

    int a[10] = {50, 0, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a)/sizeof(a[0]);
    heapSort(a, len);

    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
