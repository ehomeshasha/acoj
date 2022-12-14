#include <iostream>

using namespace std;

/**
 * 小哼的学校要建立一个图书角，老师派小哼去找一些同学做调查，看看同学们都喜欢读哪些书。小哼让每个同学写出一个自己最想读的书的ISBN号（你知道吗？每本书都有唯一的ISBN号，不信话你去找本书翻到背面看看）。
 * 当然有一些好书会有很多同学都喜欢，这样就会收集到很多重复的ISBN号。小哼需要去掉其中重复的ISBN号，即每个ISBN号只保留一个，也就说同样的书只买一本（学校真是够抠门的）。
 * 然后再把这些ISBN号从小到大排序，小哼将按照排序好的ISBN号去书店去买书。请你协助小哼完成“去重”与“排序”的工作。


输入格式:

输入有2行，第1行为一个正整数，表示有n个同学参与调查（n<=100）。第2行有n个用空格隔开的正整数，为每本图书的ISBN号（假设图书的ISBN号在1~1000之间）。
输出格式:

输出也是2行，第1行为一个正整数k，表示需要买多少本书。第2行为k个用空格隔开的正整数，为从小到大已排好序的需要购买的图书ISBN号。
提示:

改编自全国青少年信息学奥林匹克联赛（NOIP2006）普及组第一题《明明的随机数》。
限制:

每个测试点1秒

 */
int main() {
    /**
     * 思路
     * 数据量不大最多100个同学，ISBN号最大1000
     * 构建数组a[1000]存储ISBN， 排序即用计数排序就好了
     */
    int n;
    int a[1001] = {0};
    cin >> n;
    int book_num = 0;
    for (int i = 0; i < n; i++) {
        int isbn;
        cin >> isbn;
        if (a[isbn] == 0) {
            book_num++;
        }
        a[isbn]++;
    }
    cout << book_num << endl;

    /**
     * n本书的排序问题
     * 计数排序
     *
     *
     *
     */
    for (int i = 1; i <= 1000; i++) {
        if (a[i] != 0) {
            cout << i << " ";
        }
    }

    cout << endl;


    return 0;
}
