#include <iostream>

using namespace std;

/**
世博会志愿者的选拔工作正在A市如火如荼的进行。
 为了选拔最合适的人才，A市对所有报名的选手进行了笔试，笔试分数达到面试分数线的选手方可进入面试。
 面试分数线根据计划录取人数的150%划定，即如果计划录取m名志愿者，则面试分数线为排名第m*150%（向下取整）名的选手的分数，
 而最终进入面试的选手为笔试成绩不低于面试分数线的所有选手。

现在就请你编写程序划定面试分数线，并输出所有进入面试的选手的报名号和笔试成绩。

输入格式:

第一行，两个整数n，m（5 ≤ n ≤ 5000，3 ≤ m ≤ n），中间用一个空格隔开，其中n 表示报名参加笔试的选手总数，m 表示计划录取的志愿者人数。输入数据保证m*150%向下取整后小于等于n。
第二行到第 n+1 行，每行包括两个整数，中间用一个空格隔开，分别是选手的报名号k（1000 ≤ k ≤ 9999）和该选手的笔试成绩s（1 ≤ s ≤ 100）。数据保证选手的报名号各不相同。
输出格式:

第一行，有两个整数，用一个空格隔开，第一个整数表示面试分数线；第二个整数为进入面试的选手的实际人数。

从第二行开始，每行包含两个整数，中间用一个空格隔开，分别表示进入面试的选手的报名号和笔试成绩，按照笔试成绩从高到低输出，如果成绩相同，则按报名号由小到大的顺序输出。
提示:

样例说明：
m*150% = 3*150% = 4.5，向下取整后为4。保证4 个人进入面试的分数线为88，但因为88有重分，所以所有成绩大于等于88 的选手都可以进入面试，故最终有5 个人进入面试。
NOIP2009普及组
限制:

每个测试点1s。
样例 1 :

输入:
6 3
1000 90
3239 88
2390 95
7231 84
1005 95
1001 88
输出:
88 5
1005 95
2390 95
1000 90
1001 88
3239 88
 */

int main()
{
    int n, m; // 总人数、实际录取人数
    cin >> n >> m;
    int a[5000][2]; // 笔试结果
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1]; // 依次填入报名号和笔试成绩
    }

    // 数的范围很小， 因此可以使用计数排序，先对a数组进行计数排序
    int count[100] = {0}; // 笔试成绩范围[1,100]共100个数
    for (int i = 0; i < n; i++) {
        count[a[i][1]-1]++; // 压入
    }
    int tmp[5000][2]; // 临时数组存放排序结果不用了
    // LSD算法
    for (int i = 1; i < 100; i++) {
        count[i] = count[i-1] + count[i];
    }
    for (int i = n - 1; i >= 0; i--) { // 弹出
        int index = a[i][1]-1;
        tmp[count[index]-1][0] = a[i][0];
        tmp[count[index]-1][1] = a[i][1];
        count[index]--;
    }

    int limit = (m*15-5)/10;
    int cnt = 0;
    int score_line = 0;
    int score_count[100] = {0}; // 存入重复的个数
    for (int i = 0; i < n; i++) { // 反序填入
        // 结束的条件 1. cnt >= limit 且 当前分和score_line不相等
        a[i][0] = tmp[n-1-i][0];
        a[i][1] = tmp[n-1-i][1];
        if (cnt >= limit && a[i][1] != score_line) {
            break;
        }
        score_line = a[i][1];
        cnt++;
        score_count[a[i][1]-1]++;
    }

    cout << score_line << " " << cnt << endl;


    // 初排数组完成， 按照分数倒序排序， 然后进行下一步排序， 当分数相同时， 按照序号进行排序，由于数量比较小且数值范围较大1000~9999， 用冒泡排序比较合适
    int arr2[2];
    for (int i = 0; i < cnt; i++) {
        int same_cnt = score_count[a[i][1]-1]; // 相同的数字数量
        if (same_cnt != 1) {
            // 使用冒泡排序
            int (*tmp_arr)[2] = new int[same_cnt][2];
            for (int j = 0; j < same_cnt; j++) {
                tmp_arr[j][0] = a[i+j][0];
                tmp_arr[j][1] = a[i+j][1];
                // 基于tmp_arr[][0]进行排序
            }
            for (int k = 0; k < same_cnt - 1; k++) {
                for (int l = 0; l < same_cnt - 1 - k; l++) {
                    if (tmp_arr[l][0] > tmp_arr[l+1][0]) {
                        arr2[0] = tmp_arr[l][0];
                        arr2[1] = tmp_arr[l][1];
                        tmp_arr[l][0] = tmp_arr[l+1][0];
                        tmp_arr[l][1] = tmp_arr[l+1][1];
                        tmp_arr[l+1][0] = arr2[0];
                        tmp_arr[l+1][1] = arr2[1];
                    }
                }
            }
            for (int j = 0; j < same_cnt; j++) {
                cout << tmp_arr[j][0] << " " << tmp_arr[j][1] << endl;
            }
            i = i + same_cnt - 1;
            delete[] tmp_arr;
        } else {
            cout << a[i][0] << " " << a[i][1] << endl;
        }



    }


    return 0;
}
