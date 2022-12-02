#include <iostream>

using namespace std;

/**
 * 某次科研调查时得到了n个自然数，每个数均不超过1500000000（1.5*10^9）。
 * 已知不相同的数不超过10000个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。

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
 */

struct Radix {
    int sw;
    int number;
};

int calRadix(int n) {
    int radix = 1;
    for (int i = 0; i < n; i++) {
        radix *= 10;
    }
    return radix;
}

Radix* countingSort(Radix* input_arr, int len) { // O(n)
    // 取值0~9排序
    Radix* a[10] = {};
    for (int i = 0; i < len; i++) {
        Radix r = input_arr[i];
        int number = r.number;
        int sw = r.sw;
        for (int j = 0; j < len; j++) {
            if (a[sw] == nullptr) {
                a[sw] = new Radix[len];
                a[sw][0] = Radix{sw, number};
                break;
            } else if (a[sw][j].number == 0) {
                a[sw][j] = Radix{sw, number};
                break;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < len; j++) {
            if (a[i] == nullptr || a[i][j].number == 0) {
                break;
            }
            input_arr[index++] = a[i][j];
        }
    }

    return input_arr;
}

int* radixSort(int* input_arr, int len, int sw_count) {

    // 1. 遍历数位， 从个数开始
    // 初始化数位数组sw_arr
    Radix* sw_arr = new Radix[len];
    for (int i = 0; i < sw_count; i++) { // O (n)
        int radix = calRadix(i);

        // 针对第i个数位进行排序
        for (int j = 0; j < len; j++) {
            int number = input_arr[j];

            if (i != 0) { // 稳定性排序
                number = sw_arr[j].number;
            }
            int sw = number%(10*radix)/radix;
            sw_arr[j].number = number;
            sw_arr[j].sw = sw;
        }

        // 排序该数位的数字
        sw_arr = countingSort(sw_arr, len);
    }

    // 排序完毕后输入到原数组
    for (int i = 0; i < len; i++) {
        input_arr[i] = sw_arr[i].number;
    }

    return input_arr;
}



int main()
{
    /**
     * 思路
     * 先取出自然数里面为0的数进行剔除，计数0出现次数
     * 由于是正整数，且可能比较大， 因此可以用基数排序法排序
     * 排序结果再前置加上0得到最终结果
     */


    int n;
    cin >> n; // n个自然数
    int input_arr[200000] = {0}; // 通过new创建在堆上的动态数组，基本类型不会被初始化
    int zero_count = 0;
    for (int i = 0; i < n; i++) { // 遍历每个输入 O(n)
        int input_number;
        cin >> input_number;
        if (input_number == 0) {
            zero_count++;
        } else {
            input_arr[i-zero_count] = input_number; // 正整数数组
        }
    }

    /**
     * 基数排序分析
     * 总共10个数位
     *
     * 复杂度O(n)
     */
    int* result_arr = radixSort(input_arr, n-zero_count, 10);
    if (zero_count > 0) {
        cout << 0 << " " << zero_count << endl;
    }

    int last_number = 0;
    int last_number_count = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (result_arr[i] == 0) {
            continue;
        }

        if (result_arr[i] != last_number) {
            if (last_number != 0) {
                cout << result_arr[i-1] << " " << last_number_count << endl;
            }
            last_number = result_arr[i];
            last_number_count = 1;
        } else {
            last_number_count++;
        }
    }

    // 输出最后一个
    cout << result_arr[i-1] << " " << last_number_count << endl;


    return 0;
}
