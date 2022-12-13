#include <iostream>

using namespace std;

/**
给你n根火柴棍，你可以拼出多少个形如“A+B=C”的等式？等式中的A、B、C是用火柴棍拼出的整数（若该数非零，则最高位不能是0）。用火柴棍拼数字0-9的拼法如图所示：

0 -> 6
1 -> 2
2 -> 5
3 -> 5
4 -> 4
5 -> 5
6 -> 6
7 -> 3
8 -> 7
9 -> 6

注意：
1. 加号与等号各自需要两根火柴棍
2. 如果A≠B，则A+B=C与B+A=C视为不同的等式（A、B、C>=0）
3. n根火柴棍必须全部用上

 解题思路
 1. 数字对应不同的火柴棍数量
 2. + = 一共消耗4个火柴棍， 数字可用的火柴棍数量= n-4
 3. 结果可能为0， 即拼不出等式
 4. n <= 24 ，即数字火柴棍数量 <= 20
 5. 遍历法解题， 三位数  111+111=222超过20根， 因此A和B只能为两位数

输入格式:

只有一行，有一个整数n（n<=24）。
输出格式:

只有一行，表示能拼成的不同等式的数目。
提示:
*/
/**
NOIP提高组2008
限制:

每个测试点1秒
样例 1 :

输入:
14
输出:
2
说明:
2个等式为0+1=1和1+0=1。
样例 2 :

输入:
18
输出:
9
说明:
9个等式为：  0+4=4  0+11=11  1+10=11  2+2=4  2+7=9  4+0=4  7+2=9  10+1=11  11+0=11
 */

int calCount(int number, const int* arr) {
    if (number == 0) {
        return arr[0];
    }
    // 分离数位
    int cnt = 0;
    for (int i = 1;; i*=10) {
        if (i > number) {
            break;
        }
        int sw = number/i%10;
        cnt += arr[sw];
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    // 遍历第一个数A的百位
    int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    // A可能性为 0~1111
    // B可能性为 0~1111
    int formula_count = 0;
    int A, B, C;
    for (A = 0; A <= 1111; A++) {
        for (B = 0; B <= 1111; B++) {
            C = A+B;
            if (calCount(A, arr)+calCount(B, arr)+calCount(C, arr)==n-4) {
                formula_count++;
            }
        }
    }

    cout << formula_count << endl;

    return 0;
}
