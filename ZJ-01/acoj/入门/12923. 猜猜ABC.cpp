#include <iostream>

using namespace std;
int main()
{
    /**
     * 啊哈沃德发明了一个简单的数字游戏，来考一考英菲尼特。
        有三个正整数 A、B 和 C（A≤B≤C）。这些数字是保密的，他不会直接透露给英菲尼特。啊哈沃德会告诉英菲尼特七个范围在 1…1000000000 之间的整数（不一定各不相同），并宣称这是 A、B、C、A+B、B+C、C+A 和 A+B+C 的某种排列。

        给定这七个整数，请帮助英菲尼特求出 A、B 和 C。可以证明，答案是唯一的。

        输入格式:

        输入一行，包含七个空格分隔的整数。
        输出格式:

        输出 A、B 和 C，用空格分隔。
        限制:

        测试点 2-3 满足 C≤50。
        测试点 4-10 没有额外限制。
        样例 1 :

        输入:
        2 2 11 4 9 7 9
        输出:
        2 2 7
     */

    /**
     * 分析
     * 因为都是整数
     * 因此都是越加越大
     * 所以拿到7个数字先进行排序
     * A < A + B < A + C < A + B + C
     * B < A + B < B + C < A + B + C
     * C < C + A < C + B < A + B + C
     *
     * 2 2 4 7 9 9 11
     * 最大的那个数就是 A + B + C
     * 倒数第二个数 加上 第一个数 一定等于 A + B + C
     * 倒数第三个数 加上 第二个数 一定等于 A + B + C
     * 倒数第四个数 加上 第三个数 一定等于 A + B + C
     * 只有7个数因此只有这几个等式
     *
     */
    int a[7] = {0};
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    // 对7个数进行排序， 桶排序划不来， 数量很少，使用冒泡排序
    int n = 7;

    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (a[i] > a[i+1]) {
                // 如果前面比后面大， 那么就要互换， 否则不互换
                int tmp = a[i+1];
                a[i+1] = a[i];
                a[i] = tmp;
            }
        }
    }

    int A, B, C, ABC;
    ABC = a[6];
    // a[0] + a[5] = a[6];
    // a[1] + a[4] = a[6];
    // a[2] + a[3] = a[6];
    // A <= B <= C
    // A/B/C >= 1 <= 1000000000
    // 1 2 999
    // 1 2 3 999 1000 1001 1002
    // 9 9 9 18 18 18 27
    // 最小的数a[0] 一定是A，依据A<=B<=C, 因为A<=B, A<=C, A<A+B, A<A+C, A<B+C, A<A+B+C
    // 第二小的a[1] 一定是B，依据A<=B<=C, 因为B<=C, B<A+B, B<A+C, B<B+C, B<A+B+C, B>=A
    A = a[0];
    B = a[1];
    // C不一定是a[2]，也有可能是A+B，所以不可取， 直接用ABC-A-B就可以了
    C = ABC - A - B;


    cout << A << " " << B << " " << C << endl;

    return 0;
}
