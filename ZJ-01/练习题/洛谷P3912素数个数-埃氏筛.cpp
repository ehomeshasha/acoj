#include <bits/stdc++.h>
using namespace std;

/**
 * 洛谷P3912
题目描述
 求1,2,...,N中素数的个数
输入格式
 一行一个整数N
输出格式
 一行一个整数，表示素数的个数
输入样例
 10
输出样例
 4
说明/提示
 对于40%的数据，1<=N<=10^6
 对于80%的数据，1<=N<=10^7
 对于100%的数据，1<=N<=10^8
 */
bool flag[100000005]={0}; // 这里要用bool值，避免内存溢出，节约存储空间
int main()
{
    /**
     * 埃式筛法思想， 空间换时间， 数组标记所有质数的合数， 来加速筛选
     * 该方法的核心思想是：从2开始，将每个质数的倍数都标记为合数，以达到筛选素数的目的。
     * 优化点 合数标记可以从i*i开始而非2*i开始，因为是递增的，所以i之前的数都已经标记过了
     * 洛谷P3912可以AC，但不是很完美
     * 优化后的埃式筛法依然有重复标记，12会被2标记也会被3标记，我们希望一个合数只用一个素数来标记，用最小的那个
     * 引入欧式筛法
     */
    int n,cnt=0;
    cin >> n;
    int t=sqrt(n);
    for (int i=2;i<=t;i++) { // 这里可以优化成i*i因为素数一定比开根号要小
        if (flag[i]==0) {
//            for (int j=2*i;j<=n;j+=i) p[j]=1;
            for (int j=i*i;j<=n;j+=i) flag[j]=1; // 相对于上面的较快，因为小于i的前面已经标记过了
//            for (int j=i;j<=n/i;j++) p[i*j]=1; // 另一种写法
        }
    }
    for (int i=2;i<=n;i++) {
        if (flag[i]==0) cnt++;
    }
    cout << cnt;
    return 0;
}
