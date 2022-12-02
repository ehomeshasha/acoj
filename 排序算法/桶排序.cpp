#include <iostream>

#define BUCKET_NUM 30

struct Bucket {
    int len;
    int* arr;
};

int calBucketIndex(int number) {
    return (number+100)/10;
}

/**
 * 冒泡排序
 * @param input_arr
 * @param len
 * @return
 */
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

int* bucketSort(int *input_arr, int len) {
    int tmp;

    // 先分n个桶
    // 假设数字是从-100到200
    // 按照(number+100)/10来分，划分为30个桶
    Bucket* buckets = new Bucket[BUCKET_NUM];
    for (int i = 0; i < len; i++) {
        int number = input_arr[i];
        int bucket_index = calBucketIndex(number);
        if (buckets[bucket_index].len == 0) {
            // 还未初始化过
            buckets[bucket_index] = Bucket{};
            buckets[bucket_index].arr = new int[len];
            buckets[bucket_index].arr[0] = number;
        } else {
            buckets[bucket_index].arr[len-1] = number;
        }
        buckets[bucket_index].len++;
    }

    // 再对n个桶里面的元素进行比较排序
    int index = 0;
    int* result_arr = new int[len];
    for (int i = 1; i <= BUCKET_NUM; i++) {
        int* sorted_arr = bubbleSort(buckets[i].arr, buckets[i].len);
        for (int j = 0; j < buckets[i].len; j++) {
            result_arr[index++] = sorted_arr[j];
        }
    }

    return result_arr;

}



using namespace std;
int main()
{

    /**
     * 桶排序
     * 将待排序的序列分到若干个桶中，每个桶内的元素再进行个别排序。

        适用范围：数要相对均匀分布，桶的个数也要合理设计。
        需要知道输入数据的上界和下界，看看数据的分布情况，再考虑是否用桶排序
        时间复杂度： 假设桶内排序算法为快速排序，n为元素个数，m为桶个数
        O(n (log n-log m))
     */

    int a[10] = {50, 0, -58, 22, 84, 199, 20, -89, -9, 100};
    int len = sizeof(a)/sizeof(a[0]);
    int* result_arr = bucketSort(a, len);

    for (int i = 0; i < len; i++) {
        cout << result_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
