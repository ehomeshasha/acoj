#include <iostream>

int maxbit(int* a, int len) {
    // 先找最大的数
    int max = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    // 然后对最大的数求位数d
    int d = 1;
    for (int i = 0;; i++) {
        max /= 10;
        if (max == 0) {
            break;
        }
        d++;
    }
    return d;
}

void radixSort(int* a, int n) {
    int d = maxbit(a, n);
    int count[10]; // 创建计数数组
    int* tmp = new int[n]; // 创建tmp数组
    int radix = 1; // 位数初始为1
    for (int i = 1; i <= d; i++) { // 从个位数开始遍历每个位数， 每个位数进行计数排序， 然后回填到原数组
        // 个位数
        for (int j = 0; j < 10; j++) { // 初始化计数数组
            count[j] = 0;
        }
        for (int j = 0; j < n; j++) { // 遍历每个数， 分离数位
            int sw = a[j] / radix % 10;
            count[sw]++;
        }

        // 精髓来了， 因为++有累计， 所以要用空间打平， 也就是说需要构建一个tmp数组，将打平后的有序结果保存， ++类似压入， 回填的时候需要反着来， 先取n-1
        // 1. count数组按照值进行打平
        for (int j = 1; j < 10; j++) {
            count[j] = count[j] + count[j-1]; // 把值就转换成了打平的初始index
            // count[0] = 1, count[1] = 2, count[3] = 2, count[4] = 5
        }
        // 如果需要降序的话改成下面的
//        for (int j=9;j>=1;j--) {
//            count[j-1]=count[j-1]+count[j];
//        }
        // 从后往前回填
        for (int j = n - 1; j >= 0; j--) {
            int sw = a[j] / radix % 10;
            int index = count[sw] - 1; // 回填索引开始值为count[sw]-1
            tmp[index] = a[j];
            // 最后一步把count--，取相同数位的第二个数
            count[sw]--;
        }

        // tmp数组即为针对数位i排序好的临时数组，回填到原数组里面，保留稳定性
        for (int j = 0; j < n; j++) {
            a[j] = tmp[j];
        }

        // radix基数x10
        radix = radix * 10;
    }

    // 释放内存
    delete[] tmp;
}



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
    radixSort(a, len);

    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
