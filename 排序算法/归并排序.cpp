#include <iostream>

using namespace std;
// 升序
void msort_merge(int* a, int* tmp, int l, int mid, int r)
{
    int i=l,j=mid+1,idx=l;
//    // 依次比较两个半边数组第一个元素，进行归并排序 [l,mid], [mid+1,r]
//    // 先合并共同长度部分
//    while(i<=mid&&j<=r) {
//        if (a[i]<=a[j]) tmp[idx++]=a[i++];
//        else tmp[idx++]=a[j++];
//    }
//    // 再处理剩余多出来的部分，可能左边多出也可能右边多出，所以要两次
//    while (j<=r) tmp[idx++]=a[j++];
//    while (i<=mid) tmp[idx++]=a[i++];

//    自己推导的写法，就是麻烦点，也是对的
    while(true) {
        if (a[i]<=a[j]) {
            tmp[idx++]=a[i++];
        } else {
            tmp[idx++]=a[j++];
        }
        if (i>mid) { // 复制j到r之间的元素
            while(j<=r) {
                tmp[idx++]=a[j++];
            }
            break;
        }
        if (j>r) { // 复制i到mid之间的元素
            while(i<=mid) {
                tmp[idx++]=a[i++];
            }
            break;
        }
    }
    while(l<=r) {
        a[l]=tmp[l];
        l++;
    }
}

void msort_split(int* a, int* tmp, int l, int r)
{
    if (l==r) return;
    int mid=l+(r-l)/2;
    // 继续拆分左边
    msort_split(a, tmp, l, mid);
    // 继续拆分右边
    msort_split(a, tmp, mid+1, r);
    // 合并已经排序的部分
    msort_merge(a, tmp, l, mid, r);
}

void merge_sort(int* a, int n)
{
    // 递归的split直到只剩一个元素
    int l=0,r=n-1;
    int* tmp= (int*)malloc(n*sizeof(int));
    msort(a, tmp, l, r);
}












int main() {

    /**
     * 归并排序
     * 带有比较的稳定排序
     * 思路
     * 先二分后合并
     * 适用范围：
     * 时间复杂度： O(nlogn)
     */

    int a[10] = {50, 1, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a) / sizeof(a[0]);
    merge_sort(a, len);

    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}