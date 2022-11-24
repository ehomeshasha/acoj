#include <iostream>

using namespace std;
int main()
{

    /**
     * 现有一函数 digit (n,k) 分离出整数 n 从右边数第 k 个数字。
        如 digit(2076,1) 等于 6，而 digit(2076,5) 等于 0。
        输入 n 和 k，调用 digit(n,k) 输出答案，n 在 long long 范围内。

        输入格式:

        一行两个整数分别表示 n 和 k，之间用一个空格隔开。
        输出格式:

        一行一个整数，表示整数 n 从右边数第 k 个数字。
     */


    long long n;
    int k;
    cin >> n >> k;

    /**
     * 思路
     * 数位分离
     *
     * 个位 = n % (i * 10) / i
     *
     */
    int j = 0; // 代表第几个数位
    bool exist = false;
    for (long long i = 1;; i*=10) {
        if (n < i) {
            break;
        }
        j++;
        int number = n % (i * 10) / i;
        if (j == k) {
            exist = true;
            cout << number << endl;
        }
    }
    if (!exist) {
        cout << 0 << endl;
    }


    return 0;
}
