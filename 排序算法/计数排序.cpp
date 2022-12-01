#include <iostream>
#include <climits>

int* countingSort(const int *input_arr, int len) {
    // 计算最大值最小值
    int max = 0;
    int min = INT_MAX;
    for(int i = 0; i < len; i++) {
        int number = input_arr[i];
        if (number > max) {
            max = number;
        }
        if (number < min) {
            min = number;
        }
    }
    // 初始化计数数组, 默认值都为0
    int* count_arr = new int[max-min+1];
    // 遍历数值范围
    for (int i = 0; i < len; i++) {
        count_arr[input_arr[i]]++;
    }

    // 升序排序
    int ii = 0;
    int *result_arr = new int[len];
    for (int i = 0; i < max-min+1; i++) {
        while(count_arr[i] > 0) {
            result_arr[ii] = i+min;
            ii++;
            count_arr[i]--;
        }
    }
    return result_arr;

}



using namespace std;
int main()
{

    /**
     * 计数排序
     * 基础版
     *
     * 第一步：找出原数组中元素值最大的，记为max。
第二步：创建一个新数组count，其长度是max加1，其元素默认值都为0。
第三步：遍历原数组中的元素，以原数组中的元素作为count数组的索引，以原数组中的元素出现次数作为count数组的元素值。
第四步：创建结果数组result，起始索引index。
第五步：遍历count数组，找出其中元素值大于0的元素，将其对应的索引作为元素值填充到result数组中去，每处理一次，count中的该元素值减1，直到该元素值不大于0，依次处理count中剩下的元素。
第六步：返回结果数组result。

     适用范围： 自然数 0和正整数
     数字不多且分布密集
     */

    int a[10] = {50, 0, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a)/sizeof(a[0]);
    int* result_arr = countingSort(a, len);

    for (int i = 0; i < len; i++) {
        cout << result_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
