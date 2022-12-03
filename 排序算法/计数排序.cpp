#include <iostream>

void countingSort(int* a, int n) {
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    int len = max - min;
    int* count = new int[len]; // 创建计数数组
    for (int i = 0; i < n; i++) {
        count[a[i]-min]++;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        while(count[i] > 0) {
            a[index++] = i+min;
            count[i]--;
        }
    }
}


using namespace std;
int main()
{

    /**
     * 计数排序
     *  1. 找出最大值最小值
     *  2. 按照范围初始化计数数组 count[n]
     *  3. 遍历原数组中的元素， 值作为索引， 出现一次数值+1
     *  4. 回填数组

     适用范围： 自然数 0和正整数，数字不多且分布均匀密集
     时间复杂度： O(n)

     */

    int a[10] = {50, 0, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a)/sizeof(a[0]);
    countingSort(a, len);

    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
