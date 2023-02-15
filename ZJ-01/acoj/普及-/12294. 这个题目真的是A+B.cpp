#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
12294. 这个题目真的是A+B
普及和提高--
题目详情
题解
测评详情
计算A+B的值。
输入格式:

两个正整数A，B
输出格式:

A+B的值
限制:

A，B<=10^1000
样例 1 :

输入:
1 2
输出:
3
 */

int main()
{

    string A, B;
    cin >> A >> B;
    // 正整数加法
    // 从个位开始加，然后进位来求
    int la=A.length();
    int lb=B.length();
    int len = max(la, lb);
    int jinwei = 0;
    char result[1005]={'\0'};
    for (int i=1;i<=len;i++) {
        // 个位
        int a=la-i>=0?A[la-i]-'0':0;
        int b=lb-i>=0?B[lb-i]-'0':0;
        int c=a+b+jinwei;
        if (c<10) {
            jinwei=0;
        } else {
            c=c%10;
            // 进1
            jinwei=1;
        }
        result[len-i]=c+'0';
    }
    if (jinwei==1) {
        printf("%d%s", 1, result);
    } else {
        printf("%s", result);
    }


    return 0;
}
