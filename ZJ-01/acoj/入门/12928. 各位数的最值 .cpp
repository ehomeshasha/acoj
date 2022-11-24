#include <iostream>

using namespace std;
int main()
{

    /**
     * 给定三个整数 L，D，X，你需要找到两个整数 N，M使得 ：
        N 为满足条件的最小整数，L ≤ N ≤ D 且 N的各位数字之和为 X；
        M 为满足条件的最大整数，L ≤ M ≤ D且 M的各位数字之和为 X。
        保证 N,M一定存在。

        输入格式:

        输入共三行。
        第一行一个整数L，第二行一个整数D，第三行一个整数X。
        输出格式:

        输出共两行。
        第一行为一个整数N，第二行为一个整数M。
        限制:

        对于 100% 的数据，1<=L<=D<=10000， 1<=X<=36
        样例 1 :

        输入:
        1
        100
        4
        输出:
        4
        40
        样例 2 :

        输入:
        100
        500
        12
        输出:
        129
        480
     */

    /**
     * 分析
     * 1 <= L <= D <= 10000, 1 <= X <= 36
     * 分离位数的算法
     * 个位 = i % (j*10)/1
     *
     * 分别从前和从后循环遍历L和D之间的数，
     * 判断输入X是否为各数位之和， 第一个数就是就M或N
     *
     */
    int L, D, X;
    cin >> L >> D >> X;
    for (int i = L; i <= D; i++) {
        // 分离数位
        int sum = 0; // 数位之和
        for (int j = 1;; j*=10) {
            if (i < j) {
                break;
            }
            // 数位n
            int n = i % (j*10) / j;
            sum += n;
        }
        if (X == sum) {
            cout << i << endl;
            break;
        }
    }

    for (int i = D; i >= L; i--) {
        // 分离数位
        int sum = 0; // 数位之和
        for (int j = 1;; j*=10) {
            if (i < j) {
                break;
            }
            // 数位n
            int n = i % (j*10) / j;
            sum += n;
        }
        if (X == sum) {
            cout << i << endl;
            break;
        }
    }


    return 0;
}
