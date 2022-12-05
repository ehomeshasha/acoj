#include <iostream>

using namespace std;

/**
三个农民每天清晨5点起床，然后去牛棚给3头牛挤奶。
第一个农民在300秒(从5点开始计时)给他的牛挤奶，一直到1000秒。
第二个农民在700秒开始，在 1200秒结束。
第三个农民在1500秒开始2100秒结束。
期间最长的至少有一个农民在挤奶的连续时间为900秒(从300秒到1200秒)，而最长的无人挤奶的连续时间(从挤奶开始一直到挤奶结束)为300秒(从1200秒到1500秒)。
你的任务是编一个程序，读入一个有N个农民(1 <= N <= 5000)挤N头牛的工作时间列表，计算以下两点(均以秒为单位):

最长至少有一人在挤奶的时间段。
最长的无人挤奶的时间段。（从有人挤奶开始算起）
输入格式:

第1行：一个整数N。
接下来N行：每行两个小于1000000的非负整数，表示一个农民的开始时刻与结束时刻。
输出格式:

一行，两个整数，即题目所要求的两个答案。
提示:

USACO Training
限制:

每个测试点1秒
样例 1 :

输入:
3
300 1000
700 1200
1500 2100
输出:
900 300
 */

// 按照开始时间升序排序 0<=x<1000000，即自然数
void radixSort(int (*a)[3], int N, int sort_index) {
    // 最大位数
    int maxbit = 6;
    int radix = 1;
    int count[10] = {0}; // 计数排序，十进制 0-9
    int (*tmp)[2] = new int[N][2];

    for (int i = 0; i < maxbit; i++) {
        // 初始化count
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }

        // 每个数位进行排序，从个位开始, 使用计数排序
        for (int j = 0; j < N; j++) {
            int sw = a[j][sort_index] / radix % 10;
            count[sw]++; // 压入
        }

        // 拉平
        for (int j = 1; j < 10; j++) {
            count[j] = count[j-1] + count[j];
        }

        // 弹出, 从后往前遍历
        for (int j = N - 1; j >= 0; j--) {
            int sw = a[j][sort_index] / radix % 10;
            tmp[count[sw]-1][0] = a[j][0];
            tmp[count[sw]-1][1] = a[j][1];
            count[sw]--;
        }

        // 填充原数组
        for (int j = 0; j < N; j++) {
            a[j][0] = tmp[j][0];
            a[j][1] = tmp[j][1];
        }

        radix *= 10;
    }

    delete[] tmp;
}

int main()
{
    // 农民数和牛数目相等
    int N;
    cin >> N;
    int (*a)[3] = new int[N][3];
    for (int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = 0;
    }

    // 输入结束
    // 思路边界问题，求无人挤奶时间段和至少有一人挤奶时间段
    // 分别按开始时间和结束时间排序a1[N][2], a2[N][2]
    //


    // 线段合并思路
    // 遍历a1中的开始时间点， 再遍历a1中后续的时间点， 如果a[0][0] <= a[1][0] && a[0][1] >= a[1][1] ， 删除后面节点
    // 如果a[0][0] <= a[1][0] && a[0][1] < a[1][1]， 延长线段为 a[0][0], a[1][1]，删除后面节点
    //

    // 排序选择基数排序， 性能最高， 适用于比较大的正整数排序
    radixSort(a, N, 0); // 按开始时间排序
    for (int i = 0; i < N; i++) {
        if (a[i][2] == -1) {
            continue;
        }
        for (int j=i+1; j < N; j++) {
            int start2 = a[j][0];
            int end2 = a[j][1];
            if (a[j][2] == -1) {
                continue;
            }
            if (a[i][1] < start2) { // 线段无法合并，break
                break;
            }
            if (a[i][1] < end2) {
                a[i][1] = end2;
            }
            // 删除后面节点
            a[j][2] = -1;
        }
    }

    int max_time = 0;
    int max_time2 = 0;
    int last_end = 0;
    for (int i = 0; i < N; i++) {
        if (a[i][2] == -1) {
            continue;
        }
        int time = a[i][1] - a[i][0];
        if (time > max_time) {
            max_time = time; // 最长至少有一人在挤奶的时间段。
        }
        if (last_end != 0) {
            int time2 = a[i][0] - last_end;
            if (time2 > max_time2) {
                max_time2 = time2; // 最长的无人挤奶的时间段。（从有人挤奶开始算起）
            }
        }
        last_end = a[i][1];
    }

    cout << max_time << " " << max_time2 << endl;



    return 0;
}
