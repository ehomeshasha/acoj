#include <iostream>
#include <algorithm>

using namespace std;

/**
春春幼儿园举办了一年一度的“积木大赛”。今年比赛的内容是搭建一座宽度为n的大厦,大厦可以看成由n块宽度为1的积木组成,第i块积木的最终高度需要是hi。

在搭建开始之前,没有任何积木(可以看成n块高度为 0 的积木)。接下来每次操作, 小朋友们可以选择一段连续区间 [ L , R ],然后将第L块到第R块之间(含第L 块和第R块)所有积木的高度分别增加1。

小M是个聪明的小朋友,她很快想出了建造大厦的最佳策略,使得建造所需的操作次数最少。但她不是一个勤于动手的孩子,所以想请你帮忙实现这个策略,并求出最少的操作次 数。

输入格式:

输入包含两行,第一行包含一个整数n ,表示大厦的宽度。 第二行包含 n 个整数,第 i 个整数为hi。
输出格式:

仅一行,即建造所需的最少操作数。
限制:

对于 30%的数据,有1 ≤ n ≤ 10;
对于 70%的数据,有1 ≤ n ≤ 1000;
对于 100%的数据,有1 ≤ n ≤ 100000,0 ≤ hi ≤ 10000。
样例 1 :

输入:
5
2 3 4 1 2
输出:
5
说明:
其中一种可行的最佳方案,依次选择
[1,5] [1,3] [2,3] [3,3] [5,5]
 */

int main()
{
    // 贪心思想
    // 找出最优解，即最有效率方式
    // 效率表达式： 最大的宽度（0和结尾为分割点）， 扣减最多的层数（minH）
    // 结束条件：

    // 每个层取最大宽度即可
    int n;
    int a[1000001];
    cin >> n;
//    int maxH = 0;
    int optCnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
//        if (a[i] > maxH) maxH = a[i];
    }
    // 优化算法，遍历n


    bool stop = false;
    int b[10005][3];

    while (!stop) {


        int minH = 10005, start = 1, end = 1, k = 1;
        bool isStart = false;

        for (int i = 1; i <= n; i++) {
            if (a[i] < minH && a[i] != 0) {
                minH = a[i];
            }
            if (a[i]!=0&&!isStart) {
                start=i;
                isStart = true;
            }
            if ((a[i-1]!=0&&a[i]==0) || (a[i]!=0&&i==n)) {
                end = i!=n ? i-1: i;
                b[k][0] = start;
                b[k][1] = end;
                b[k][2] = minH;
                k++;
                isStart = false;
            }
        }

        for (int i = 1; i < k; i++) {
            for (int j = b[i][0]; j <= b[i][1]; j++) {
                a[j] = a[j] - b[i][2];
            }
            optCnt += b[i][2];
        }


        bool isStop = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                isStop = false;
                break;
            }
        }
        stop = isStop;
    }



    // 遍历每一层
//    for (int i = 1; i <= maxH; i++) {
//        // 每层按照剩余高度计算最大宽度， 并按照从大到小排序
//        // 遍历排序好的数组，依次扣减，更新a[i]
//        // 扣减一个范围， 操作次数+1
//
//        // gap问题求解, 优化
//        // 遇到第一个非0， 操作次数+1
//        bool firstNoneZero = false;
//        for (int j = 1; j <= n; j++) {
//            if (a[j] != 0) {
//                if (!firstNoneZero) {
//                    optCnt++;
//                    firstNoneZero = true;
//                }
//                a[j] = a[j] - 1;
//            } else {
//                firstNoneZero = false;
//            }
//        }
//    }

    // 输出操作次数
    cout << optCnt << endl;

    return 0;
}
