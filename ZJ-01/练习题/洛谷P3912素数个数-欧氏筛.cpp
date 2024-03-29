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
int pm[100000005]={0},pm_idx=0;
int main()
{
    /**
     * 基于埃氏筛，一个合数只由他最小的质因子来筛选一次
     * 思想很容易， 实现是难点
     * 核心 - 增加一个质数数组， 合数标记转为i*质数数组中的元素来标记， 注意遇到i%pm[j]==0break
     *
     * 步骤
     * 1. 增加质数数组，每找到一个质数就加入该数组
     * 2. 依次遍历质数数组中的质数，和i相乘，停止条件为到最后一个元素或i*pm[j]超过n越界
     * 3. 将每个i*pm[j]标记为合数
     * 4. 如果i%pm[j]整除，那么后面的j+1,j+2等等都不是最小质因子分解，break
     * 步骤4证明
     * 考虑后续的j+1情况，i*pm[j+1]=pm[j]*q*pm[j+1]=pm[j]*(q*pm[j+1]),pm是一个升序数组，pm[j+1]>pm[j]，所以pm[j+1]一定不是最小的质数，放弃标记
     */
    int n;
    cin >> n;
    for (int i=2;i<=n;i++) {
        if (flag[i]==0) {
            pm[pm_idx++]=i;
        }
        for (int j=0;j<pm_idx&&i*pm[j]<=n;j++) {
            flag[i*pm[j]]=1; // 素数数组里面每个元素都乘以i标记一次
            if (i%pm[j]==0) break; // 表示i*pm[j+1]不是他的最小质因子分解
        }
    }
    cout << pm_idx;
    return 0;
}
