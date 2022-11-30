#include <iostream>

using namespace std;

/**
 * 某次科研调查时得到了n个自然数，每个数均不超过1500000000（1.5*10^9）。
 * 已知不相同的数不超过10000个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。
 *
输入格式:

第1行是整数n(1<=n<=200000)，表示自然数的个数。
第2~n+1行每行一个自然数。
输出格式:

输出包含m行（m为n个自然数中不相同数的个数），按照自然数从小到大的顺序输出。每行输出两个整数，分别是自然数和该数出现的次数，其间用一个空格隔开。
提示:

NOIP2007提高组
限制:

每个测试点1s。
40%的数据满足：1<=n<=1000
80%的数据满足：1<=n<=50000
100%的数据满足：1<=n<=200000，每个数均不超过1500 000 000（1.5*10^9）

 *
 * 分析， int类型最大到20亿 ，目前题目给出最大数是15亿， 可以存储
 *
 * 不相同的数不超过10000个， 而自然数的个数不超过20万
 *
 * 冒泡排序才n^2=1亿时间复杂度
 *
 *
 */
struct Stat {
    int number;
    int count;
};

int main()
{
    int n, input;
    Stat a[10000] = {0, 0}; // 存储不同自然数以及出现次数
    int count = 0; // 不同的数的计数
    cin >> n;
    for (int i = 0; i < n; i++) {
        // 遍历每个数
        cin >> input;
        for (int j = 0;; j++) {
            // 如果number匹配
            if (a[j].number == input) {
                a[j].count++;
                if (input == 0 && a[j].count == 0) {
                    count++;
                }
                break;
            } else if (a[j].number == 0) { // 如果到最后都没有匹配上的
                a[j].number = input;
                a[j].count++;
                count++;
                break;
            }
        }
    }

    /**
     * 排序这1万个数
     * 冒泡排序法
     * 升序
     *
     */
    Stat tmp{};
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (a[j].number > a[j+1].number) {
                // 三变量法, 互换
                tmp.number = a[j].number;
                tmp.count = a[j].count;

                a[j].number = a[j+1].number;
                a[j].count = a[j+1].count;

                a[j+1].number = tmp.number;
                a[j+1].count = tmp.count;
            }
        }
    }

    // 升序输出
    for (int i = 0; i < count; i++) {
        cout << a[i].number << " " << a[i].count << endl;
    }

    return 0;
}
