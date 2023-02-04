#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
Zeratul有6个数，现在你要输出其中最大的两个数加起来等于多少。
输入格式:
一行，包括六个整数。
输出格式:
最大的两个数的和。
限制:
这些数都是小于1000的正整数
样例 1 :
输入:
5 6 7 10 9 8
输出:
19
 */

int main()
{
    int a[6];
    for (int i=0;i<6;i++)
        cin >> a[i];
    int tmp;
    // 冒泡排序
    for (int i=0;i<6-1;i++) {
        for(int j=0;j<6-1-i;j++) {
            if (a[j]<a[j+1]) {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    cout << a[0]+a[1] << endl;
    return 0;
}
