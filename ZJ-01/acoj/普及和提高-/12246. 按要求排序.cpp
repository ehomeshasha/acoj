#include <bits/stdc++.h>


using namespace std;

/**
从键盘输入n个数，根据要求进行排序。
输入格式:
共n+1行。
第一行两个数n m。（n表示n个数，m表示排序的方式，m为1时从大到小排序，m为0
时从小到大排序）
输出格式:
共1行。
按照要求输出。每个数用一个空格间隔开
限制:
20%的数据满足：0<=A、B<=16000 n<=10
40%的数据满足：0<=A、B<=32767 n<=100
100%的数据满足：0<=A、B<=10^9 n<=1000
样例 1 :
输入:
5 1
1 2 5 2 3
输出:
5 3 2 2 1
样例 2 :
输入:
10 0
10 9 8 7 6 5 4 3 2 1
输出:
1 2 3 4 5 6 7 8 9 10
 */
/**
 * 直接用sort也行，但是可以
 * 默写一遍基数排序，比较较大的数
 */
int maxbit(const int* a, int n)
{
    int maxn=0;
    for (int i=0;i<n;i++) {
        if (maxn<a[i]) maxn=a[i];
    }
    int r=1,res=0;
    for (;;) {
        if(maxn<r) break;
        res++,r*=10;
    }
    return res;
}

void mprint(const int* a, int n)
{
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    cout << endl;
}

void radix_sort(int* a, int n, bool asc)
{
    int len=maxbit(a,n),count[10];
    int* tmp=new int[n];
    int r=1;
    for (int i=0;i<len;i++) { // 遍历每个数位，从个位开始
        // 初始化计数数组
        for (int j=0;j<10;j++) count[j]=0;
        // 正序填入计数数组
        for (int j=0;j<n;j++) {
            int sw=a[j]%(10*r)/r;
            count[sw]++;
        }
        // 计数数组做累加，好存储所有数
        if (asc) { // 升序
            for (int j=1;j<10;j++) count[j]=count[j]+count[j-1];
        } else { // 降序
            for (int j=9;j>=1;j--) count[j-1]=count[j-1]+count[j];
        }
        // 逆序回填临时数组
        for (int j=n-1;j>=0;j--) {
            int sw=a[j]%(10*r)/r;
            tmp[count[sw]-1]=a[j];
            count[sw]--;
        }
        // 将临时数组写入原始数组
        for (int j=0;j<n;j++) a[j]=tmp[j];
//        mprint(a,n);
        r*=10;
    }
    delete[] tmp;
}
int main()
{
    int N,M,a[1000];
    scanf("%d %d\n",&N,&M);
    bool sort_type=M==0?1:0;
    for (int i=0;i<N;i++) scanf("%d ",&a[i]);
    radix_sort(a,N,sort_type);
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    return 0;
}
