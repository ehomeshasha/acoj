#include <iostream>

// ------------------ 网上算法 start ----------------- //

int calSwCount(int data[], int n) //辅助函数，求数据的最大位数
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


void radixSort(int data[], int n, int asc) //基数排序
{
    int sw_count = calSwCount(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= sw_count; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++) {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }

        if (asc == 1) {
            // 50, 1, 58, 22, 84, 199, 20, 89, 9, 100
            // 0, 1, 8, 2, 4, 9, 0, 9, 9, 0
            // count[0] = 3, count[1] = 1, count[2] = 1, count[4] = 1, count[8] = 1, count[9] = 3
            // count[0] = 3, count[1] = 4, count[2] = 5, count[3] = 5, count[4] = 6, count[5] = 6, count[6] = [6], count[7] = 6, count[8] = 7, count[9] = 10

            for (j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        } else {
            // 50, 1, 58, 22, 84, 199, 20, 89, 9, 100
            // 0, 1, 8, 2, 4, 9, 0, 9, 9, 0
            // count[0] = 3, count[1] = 1, count[2] = 1, count[4] = 1, count[8] = 1, count[9] = 3
            // count[0] = 10, count[1] = 7, count[2] = 6, count[3] = 5, count[4] = 5, count[5] = 4, count[6] = 4, count[7] = 4, count[8] = 4, count[9] = 3
            for (j = 9; j >= 1; j--)
                count[j-1] = count[j-1] + count[j]; //将tmp中的位置倒序分配给每个桶
        }

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
        for (j = n - 1; j >= 0; j--) { //将所有桶中记录依次收集到tmp中
            // 为什么倒序填充， 基于堆栈思想， count++是压入从0到n-1，因此count--就是弹出从n-1到0
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }

        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
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

    int a[10] = {50, 1, 58, -22, -84, 199, 0, 89, 9, 100};
    int len = sizeof(a) / sizeof(a[0]);
    int* negative_count_arr = new int[len];
    int* positive_count_arr = new int[len];

    // 拆分成0、正数、负数
    int zero_count = 0;
    int negative_count = 0;
    int positive_count = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 0) {
            zero_count++;
        } else if (a[i] < 0) {
            negative_count_arr[negative_count] = -a[i];
            negative_count++;
        } else if (a[i] > 0) {
            positive_count_arr[positive_count] = a[i];
            positive_count++;
        }
    }

    // 排序负数数组
    radixSort(negative_count_arr, negative_count, 0);

    // 排序正数数组
    radixSort(positive_count_arr, positive_count, 1);

    // 拼接最终结果
    for (int i = 0; i < negative_count; i++) {
        cout << -negative_count_arr[i] << " ";
    }
    for (int i = 0; i < zero_count; i++) {
        cout << 0 << " ";
    }
    for (int i = 0; i < positive_count; i++) {
        cout << positive_count_arr[i] << " ";
    }

    cout << endl;

    return 0;
}
