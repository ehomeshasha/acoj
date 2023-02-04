#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

/**
输出A XOR B（即C++中的“^”运算符）的结果。
输入格式:
第一行一个整数q，代表数据组数。
接下来q行，每行两个整数a，b。
输出格式:
对于每组查询，输出一行，按输入原样输出a和b，a，b用空格隔开。
限制:
0<=a,b<=10^9
q<=2.5*10^6
样例 1 :
输入:
2
1 2
3 4
输出:
3
7
 */

int main()
{
    int q,a,b;
    cin >> q;


    for(int i=1;i<=q;i++) {
        // 不能使用cin/cout，一用就超时
        scanf("%d %d", &a, &b);
        printf("%d\n", a^b);
    }

    return 0;
}
