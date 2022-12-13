#include <iostream>
#include<algorithm>

bool descCompare(int a, int b) {
    return a > b;
}

using namespace std;

/**
在一个夜黑风高,下着暴风雨的夜晚,farmer John的牛棚的屋顶、门被吹飞了。 好在许多牛正在度假，所以牛棚没有住满。
牛棚一个紧挨着另一个被排成一行，牛就住在里面过夜。 有些牛棚里有牛，有些没有。 所有的牛棚有相同的宽度。
自门遗失以后,farmer John必须尽快在牛棚之前竖立起新的木板。
他的新木材供应商将会供应他任何他想要的长度,但是吝啬的供应商只能提供有限数目的木板。
farmer John想将他购买的木板总长度减到最少。
给出:
可能买到的木板最大的数目M(1<= M<=50);
牛棚的总数S(1<= S<=200);
牛棚里牛的总数C(1 <= C <=S);
和牛所在的牛棚的编号stall_number(1 <= stall_number <= S),计算拦住所有有牛的牛棚所需木板的最小总长度。

输出所需木板的最小总长度作为答案。

输入格式:

第 1 行: 木板最大的数目M ,牛棚的总数S 和 牛的总数C(用空格分开)
第 2 到 C+1行: 每行包含一个整数，表示牛所占的牛棚的编号。
输出格式:

单独的一行包含一个整数表示所需木板的最小总长度。
*/
/**
提示:

USACO Training
限制:

每个测试点1秒
样例 1 :

输入:
4 50 18
3
4
6
8
14
15
16
17
21
25
26
27
30
31
40
41
42
43
输出:
25
说明:
[ 一种最优的安排是用板拦牛棚3-8,14-21,25-31,40-43.]

 */

int main()
{
    int M, S, C;
    cin >> M >> S >> C;

    /**
     * 0. 需要先对编号排序
     * 1. 每只牛挨个搭木板
     * 2. 从大往小排序木板
     * 3. 初始木板为1， 拿掉一个最大的木板， 木板数量+1， 最终达到M终止
     * 4. 用首尾牛距离-拿掉木板总长度即为结果
     */
    int data[200];
    for (int i = 0; i < C; i++) {
        int stall_number;
        cin >> stall_number;
        data[i] = stall_number;
    }

    sort(data+0, data+C);
    // 冒泡排序
//    int tmp;
//    for (int i = 0; i < C-1; i++) {
//        for (int j = 0; j < C-1-i; j++) {
//            if (data[j] > data[j+1]) {
//                tmp = data[j];
//                data[j] = data[j+1];
//                data[j+1] = tmp;
//            }
//        }
//    }

    // 去掉首尾进行遍历
    // 0 1 2 3 4 5 6 7 8 9 10
    //       * *   *   *
    // 3-8
    // 3-4 4-6 6-8
    int board_arr[200];
    for (int i = 0; i < C-1; i++) {
        board_arr[i]=data[i+1]-data[i]-1;
    }

    // 从大往小排序board_arr
//    for (int i = 0; i < C-1-1; i++) {
//        for (int j = 0; j < C-1-1-i; j++) {
//            if (board_arr[j] < board_arr[j+1]) {
//                tmp = board_arr[j];
//                board_arr[j] = board_arr[j+1];
//                board_arr[j+1] = tmp;
//            }
//        }
//    }
    sort(board_arr+0, board_arr+C-1, descCompare);

    // 从最大的板子开始去掉
    int board_cnt = 1;
    int board_min_len = data[C-1]-data[0]+1;
    for (int i = 0; i < C-1; i++) {
        if (board_cnt == M) {
            break;
        }
        board_min_len -= board_arr[i];
        board_cnt++;
    }

    cout << board_min_len << endl;

    return 0;
}