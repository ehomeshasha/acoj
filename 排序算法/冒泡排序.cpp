#include <iostream>
#include <climits>

int* bubbleSort(int *input_arr, int len) {
    int tmp;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1-i; j++) {
            // 对比相邻元素
            if (input_arr[j] > input_arr[j+1]) {
                tmp = input_arr[j];
                input_arr[j] = input_arr[j+1];
                input_arr[j+1] = tmp;
            }
        }
    }
    return input_arr;

}



using namespace std;
int main()
{

    /**
     * 冒泡排序
     * 第一层对比n-1次， 相邻元素进行对比， 如果排序不符则进行互换
     * 第二层对比n-2次，以此类推，一直到最后一层对比1次

     适用范围： 任意数据类型、数据不多、时间复杂度O(n)~O(n^2)
     */

    int a[10] = {50, 0, 58, 22, 84, 199, 20, 89, 9, 100};
    int len = sizeof(a)/sizeof(a[0]);
    int* result_arr = bubbleSort(a, len);

    for (int i = 0; i < len; i++) {
        cout << result_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
