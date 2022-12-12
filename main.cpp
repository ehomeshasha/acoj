#include <iostream>

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
     * 0. 需要先排序
     * 1. 求出空隙数组
     * 2. 从大往小排序
     * 3. 初始木板为1， 拿到一个空隙数组， 木板数量+1， 最终达到M终止
     * 4. 计算用到空隙数组的总长度
     * 5. 用牛棚总长度-空隙数组总长度得到结果
     */
    int data[200];
    for (int i = 1; i <= C; i++) {
        int stall_number;
        cin >> stall_number;
        data[i-1] = stall_number;
    }

    // 冒泡排序
    int tmp;
    for (int i = 0; i < C-1; i++) {
        for (int j = 0; j < C-1-i; j++) {
            if (data[j] > data[j+1]) {
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }

    int empty_arr[200][3];
    int n = 0;
    empty_arr[n][0] = 1;
    for (int i = 0; i < C; i++) {
        int stall_number = data[i];
        empty_arr[n][1] = stall_number;
        empty_arr[n][2] = n;
        empty_arr[n+1][0] = stall_number+1;
        n++;
    }
    empty_arr[n][1] = S+1;
    empty_arr[n][2] = n;
    n++;

    // 排序， 数据量较小用冒泡排序 ， 降序排序
    int temp[3];
    for (int i = 0; i < n-1; i++) { // empty_arr有n个元素
        for (int j = 0; j < n-1-i; j++) {
            int len1 = empty_arr[j][1]-empty_arr[j][0];
            int len2 = empty_arr[j+1][1]-empty_arr[j+1][0];
            if (len1 < len2) {
                temp[0] = empty_arr[j][0];
                temp[1] = empty_arr[j][1];
                temp[2] = empty_arr[j][2];
                empty_arr[j][0] = empty_arr[j+1][0];
                empty_arr[j][1] = empty_arr[j+1][1];
                empty_arr[j][2] = empty_arr[j+1][2];
                empty_arr[j+1][0] = temp[0];
                empty_arr[j+1][1] = temp[1];
                empty_arr[j+1][2] = temp[2];
            }
        }
    }
    // 贪心算法
    // 从大往下去掉空隙，去掉一次空隙所需木板+1， 木板数量初始为1， 增加终止条件为木板数量大于等于M
    // 如果是首尾木板， 则不增加木板长度， 强制去掉空隙
    // 求空隙总长度
    int empty_len_sum = 0;
    int board_cnt = 1;

    for (int i = 0; i < n; i++) {
        int* a = empty_arr[i];
        int empty_len = a[1] - a[0];
        if (a[2] == 0 || a[2] == C) {
            empty_len_sum += empty_len;
        }  else {
            if (board_cnt < M) {
                empty_len_sum += empty_len;
                board_cnt++;
            }
        }
    }


    int board_len_sum = S-empty_len_sum;
    cout << board_len_sum << endl;

    return 0;
}
