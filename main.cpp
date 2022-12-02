#include <iostream>

// ------------------ 自己写的旧算法 start ----------------- //

int calRadixM1(int n) {
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

Radix *countingSortM1(Radix *input_arr, int len) {
    // 只能0-9数字，就很简单， 但是需要用稳定排序？感觉不需要
    // 另外有个难点是要将数字和关联
    Radix *a[10] = {};
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
        Radix *arr = a[i];
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


int *radixSortM1(int *input_arr, int len, int sw_count) {
    Radix *sw_arr = new Radix[len];
    for (int i = 0; i < sw_count; i++) {
        int radix = calRadixM1(i);
        // 第i次依据数位排序
        for (int j = 0; j < len; j++) {
            if (i == 0) {
                int number = input_arr[j];
                int sw = number % (10 * radix) / radix;
                sw_arr[j] = {sw, number};
            } else {
                // 稳定性排序
                int number = sw_arr[j].number;
                int sw = number % (10 * radix) / radix;
                sw_arr[j].sw = sw;
            }
        }

        // 排序该数位的数字
        sw_arr = countingSortM1(sw_arr, len);
    }

    // 排序完毕后输入到原数组
    for (int i = 0; i < len; i++) {
        input_arr[i] = sw_arr[i].number;
    }
    return input_arr;
}



// ------------------ 自己写的旧算法 end ----------------- //



// ------------------ 网上算法 start ----------------- //

int maxbitW1(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];              ///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i) {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p) {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
}


void radixsortW1(int data[], int n) //基数排序
{
    int d = maxbitW1(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++) {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        // 50, 1, 58, 22, 84, 199, 20, 89, 9, 100
        // 0, 1, 8, 2, 4, 9, 0, 9, 9, 0
        // count[0] = 3, count[1] = 1, count[2] = 1, count[4] = 1, count[8] = 1, count[9] = 3
        // count[0] = 3, count[1] = 4, count[2] = 5, count[3] = 5, count[4] = 6, count[5] = 6, count[6] = [6], count[7] = 6, count[8] = 7, count[9] = 10


        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶

        // number = 100
        // k = 0;
        // count[0] = 3
        // tmp[2] = 100
        // count[0] = 2

        // number = 9
        // k = 9
        // count[9] = 10
        // tmp[9] = 9
        // count[9] = 9
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }

    // 指针需要删除
    delete[]tmp;
    delete[]count;
}


// ------------------ 网上算法 end ----------------- //











using namespace std;

int main() {

    /**
     * 基数排序
     * 将所有待比较数值(注意,必须是正整数)统一为同样的数位长度,数位较短的数前面补零.
     * 然后, 从最低位开始, 依次进行一次稳定排序(常用计数排序算法, 因为每个位可能的取值范围是固定的从0到9).
     * 这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列.

        适用范围： 正整数， 数据可以稀疏也可以不均匀，适合很大的数比较
        时间复杂度： O(n)
     */

    int a[10] = {50, 1, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a) / sizeof(a[0]);
    radixsortW1(a, len);

    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
