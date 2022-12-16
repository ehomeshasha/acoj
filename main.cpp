#include <iostream>

using namespace std;

/**
已知 n 个整数 x1,x2,…,xn，以及一个整数 k（k＜n）。
从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。
例如当 n=4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：

3＋7＋12=22　　3＋7＋19＝29　　7＋12＋19＝38　　3＋12＋19＝34。

现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：3＋7＋19＝29）。
*/
/**
输入格式:

n , k （1<=n<=20，k＜n）
x1,x2，…,xn （1<=xi<=5000000
输出格式:

一个整数（满足条件的种数）。
提示:

noip2002普及组第二题
限制:

每个测试点1s
样例 1 :

输入:
4 3
3 7 12 19
输出:
1
 */

bool isPrime(long long number) {
    if (number == 0 || number == 1) return false;
    if (number == 2) return true;
    for (long long i = 2; i * i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}





/**
     * x1, x2, x3, x4, x5
     * x1, x2, x3
     * x1, x2, x4
     * x1, x2, x5
     * x1, x3, x4
     * x1, x3, x5
     * x1, x4, x5
     * 3 7 12 19
     * 3 7 12 - 0 1 2 第三层， 可选 2， 3
     * 3 7 19 - 0 2 3 第二层， 可选 1， 2
     * 3 12 19 - 0 2 3 第一层， 可选 0， 1
     * 7 12 19 - 1 2 3
     */
int prime_cnt = 0;
void dfs(int* data, int start, int cnt, long long sum, int layer_cnt, int n, int k) {
    layer_cnt++;
    for (int i = start; i < n; i++) {
        if (i > layer_cnt) {
            continue;
        }
        int value = data[i];
        sum += value;
        cnt++;
        start++;
        if (cnt == k) {
            if (isPrime(sum)) {
                prime_cnt++;
            }
            cnt--;
            sum -= value;
            continue;
        }
        dfs(data, start, cnt, sum, layer_cnt, n, k);
        cnt--;
        sum -= value;
    }
}

// 第一层 i = 0 3
// 第二层 i = 1 7
// 第三层 i = 2 12
// 退回第二层 i = 1 7
// 再进入第三层 i = 3 19

int main()
{

    int n, k;
    cin >> n >> k;
    int data[20];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    dfs(data, 0, 0, 0, 0, n, k);
    cout << prime_cnt << endl;
    return 0;
}
