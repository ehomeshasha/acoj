#include <iostream>

int calRadix(int n) {
    int radix = 1;
    for (int i = 0; i < n; i++) {
        radix *= 10;
    }
    return radix;
}

struct Radix {
    int sw;
    int number;
};

Radix* countingSort(Radix *input_arr, int len) {
    // 只能0-9数字，就很简单， 但是需要用稳定排序？感觉不需要
    // 另外有个难点是要将数字和关联
    Radix* a[10] = {};
    for (int i = 0; i < len; i++) {
        int sw = input_arr[i].sw;
        int number = input_arr[i].number;
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
        Radix* arr = a[i];
        for (int j = 0; j < len; j++) {
            if (arr == nullptr || arr[j].number == 0) {
                break;
            }
            input_arr[index] = arr[j];
            index++;
        }
    }
    return input_arr;
}



int* radixSort(int* input_arr, int len, int sw_count) {
    Radix* sw_arr = new Radix[len];
    for (int i = 0; i < sw_count; i++) {
        int radix = calRadix(i);
        // 第i次依据数位排序
        for (int j = 0; j < len; j++) {
            if (i == 0) {
                int number = input_arr[j];
                int sw = number % (10*radix) / radix;
                sw_arr[j] = {sw, number};
            } else {
                // 稳定性排序
                int number = sw_arr[j].number;
                int sw = number % (10*radix) / radix;
                sw_arr[j].sw = sw;
            }
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

using namespace std;
int main()
{

    /**
     * 基数排序
     * 将所有待比较数值(注意,必须是正整数)统一为同样的数位长度,数位较短的数前面补零.
     * 然后, 从最低位开始, 依次进行一次稳定排序(常用计数排序算法, 因为每个位可能的取值范围是固定的从0到9).
     * 这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列.

        适用范围： 正整数， 数据可以稀疏也可以不均匀，适合很大的数比较
        时间复杂度： O(n)
     */

    int a[10] = {50, 1, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a)/sizeof(a[0]);
    int* result_arr = radixSort(a, len, 3);

    for (int i = 0; i < len; i++) {
        cout << result_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
