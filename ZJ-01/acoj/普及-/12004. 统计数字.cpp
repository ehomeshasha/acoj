#include <iostream>



// ------------------ 网上算法 start ----------------- //



void radixSortW1(int data[], int n, int d) //基数排序
{
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
    radixSortW1(input_arr, n-zero_count, 10);
    int* result_arr = input_arr;
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
