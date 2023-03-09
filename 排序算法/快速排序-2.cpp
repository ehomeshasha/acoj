#include <iostream>

using namespace std;


int partition(int* a, int l, int r)
{
    int i=l,j=r,flag=0;
    // 随机枢轴
    int ran_idx=rand()%(r-l+1)+l;
    swap(a[ran_idx],a[l]);
    int bn=a[l];
    while(i<j) {
        if (flag==0) { // 右侧机器人j工作
            if (a[j]<bn) {
                swap(a[i++],a[j]);
                flag=1;
            } else {
                j--;
            }
        } else { // 左侧机器人i工作
            if (a[i]>bn) {
                swap(a[i],a[j--]);
                flag=0;
            } else {
                i++;
            }
        }
    }
    return i;
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
     * 快速排序-2
     * 带有比较的稳定排序，通过比较基准数分成左右两部分
     * 思路
     * 机器人丢箱子法， 两个左右端点机器人，轮流丢箱子
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