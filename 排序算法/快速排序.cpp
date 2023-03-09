#include <iostream>

using namespace std;





void quick_sort(int* a, int l, int r)
{
    if (l>=r) return; // 只剩一个元素或者超出
    // 划分的算法， 最后一个元素作为pivot，扫一遍，然后小的移动到前面去
    // https://selfboot.cn/2016/09/01/lost_partition/ 算法思路
    int i=l;
    for (int j=l;j<r;j++) {
        if (a[j]<a[r]) swap(a[i++],a[j]);
    }
    swap(a[i],a[r]); // 最后把最后一个元素放到该放的地方
    quick_sort(a,l,i-1);
    quick_sort(a,i+1,r);
}



int main() {

    /**
     * 快速排序
     * 带有比较的稳定排序，通过比较基准数分成左右两部分
     * 思路
     * 不断选择基准数，并进行比较划分左右部分，只剩一个元素停止，每次划分基准都可以找到一个正确位置
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