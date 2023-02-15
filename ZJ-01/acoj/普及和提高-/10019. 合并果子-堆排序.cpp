#include <bits/stdc++.h>


using namespace std;

/**
在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。
 可以看出，所有的果子经过n-1次合并之后，就只剩下一堆了。
 多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。
 假定每个果子重量都为1，并且已知果子的种类数和每种果子的数目，
 你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
例如有3种果子，数目依次为1，2，9。可以先将1、2堆合并，新堆数目为3，耗费体力为3。
 接着，将新堆与原先的第三堆合并，又得到新的堆，数目为12，耗费体力为12。所以多多总共耗费体力=3+12=15。可以证明15为最小的体力耗费值。
输入格式:
输入包括两行，第一行是一个整数n(1<＝n<=100000)，表示果子的种类数。
 第二行包含n个整数，用空格分隔，第i个整数ai(1<＝ai<=20000)是第i种果子的数目。
输出格式:
输出包括一行，这一行只包含一个整数，也就是最小的体力耗费值。输入数据保证这个值小于2^31。
提示:
NOIp 2004
限制:
对于30%的数据，保证有n <= 1000；
对于50%的数据，保证有n <= 5000；
对于全部的数据，保证有n <= 100000。
样例 1 :
输入:
3
1 2 9
输出:
15
 */
int sum=0;
// 小顶堆 - 父亲节点都不大于孩子节点
// 堆化
void heapify(int* arr, int n, int i)
{
    // 找出最小的
    int min=i,lson=i*2+1,rson=i*2+2;
    if (lson<n&&arr[min]>arr[lson]) min=lson;
    if (rson<n&&arr[min]>arr[rson]) min=rson;
    if (min!=i) {
        swap(arr[min],arr[i]);
        heapify(arr,n,min);
    }
}

void create_heap(int* arr, int n)
{
    // 建堆 - 从最后元素的父节点开始 (n-1-1)/2
    for (int i=n/2-1;i>=0;i--) {
        heapify(arr,n,i);
    }
}

// 取出最小的
// 堆化
// 取出最小的
// 计算min1+min2得到sum_t
// 将sum_t赋值给堆顶
// 堆化
// 继续循环
void hebing(int* arr, int n)
{
    int min1=arr[0];
    swap(arr[0],arr[n-1]);
    heapify(arr,n-1,0);
    int min2=arr[0];
    int sum_t=min1+min2;
    sum+=sum_t;
    arr[0]=sum_t;
    heapify(arr,n-1,0);
}

int main()
{
    int n,a[100005];
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    // 建堆
    create_heap(a,n);
    // 计算
    for (int i=n;i>1;i--) {
        hebing(a,i);
    }
    cout << sum;
    return 0;
}
