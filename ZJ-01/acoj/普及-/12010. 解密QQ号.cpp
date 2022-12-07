#include <iostream>

using namespace std;

/**
新学期开始了，小哈是小哼的新同，小哼向小哈询问QQ号，小哈当然不会直接告诉小哼。
 所以小哈给了小哼一串加密过的数字，同时小哈也告诉了小哼解密规则。
 规则是这样的：首先将第1个数删除，紧接着将第2个数放到这串数的末尾，
 再将第3个数删除并将第4个数再放到这串数的末尾，再将第5个数删除……直到剩下最后一个数，将最后一个数也删除。
 按照刚才删除的顺序，把这些删除的数连在一起就是小哈的QQ啦。
 现在你来帮帮小哼吧。小哈给小哼加密过的一串数是“6 3 1 7 5 8 9 2 4”。解密后小哈的QQ号应该是“6 1 5 9 4 7 2 8 3”。

输入格式:

只有2行
第1行有一个整数n （1<=n<=100000）
第2行有n个整数为加密过的QQ号，每个整数之间用空格隔开。每个整数在1~9之间。
输出格式:

只有一行，输出解密后的QQ号。
限制:

每个测试点1秒
50%的数据1<=n<=10000
100%的数据1<=n<=100000
样例 1 :

输入:
9
6 3 1 7 5 8 9 2 4
输出:
6 1 5 9 4 7 2 8 3
 */


int main()
{
    int n;
    cin >> n; // 1<=n<=100000
    int* a = new int[2*n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 每个整数1~9
    }
    /**
     * 规则是这样的：首先将第1个数删除，紧接着将第2个数放到这串数的末尾，
 再将第3个数删除并将第4个数再放到这串数的末尾，再将第5个数删除……直到剩下最后一个数，将最后一个数也删除。
 按照刚才删除的顺序，把这些删除的数连在一起就是小哈的QQ啦。
     */
    // 好像是个堆栈问题， 删除的数就是头部的数， 移动的数就是压入的数
    // 首先将原数组1、3、5、7、9，依次剔除， 然后2、4、6、8、10数依次放到末尾，如果数组放大到1.5n并向上取整， 一定放得下， 被删除的
    // 循环问题
    for (int i = 0; i < n; i++) { // i 等同于delete_count
        // 6 3 1 7 5 8 9 2 4, n = 9, i = 0
        // 0 1 2 3 4 5 6 7 8
        // 处理后，数字保持不变，下次取数会从2开始，因此相当于6和3被删除了， 而整个数组需要长度要+1，多了一个下标9，去添加3
        // 6 3 1 7 5 8 9 2 4 3
        // 0 1 2 3 4 5 6 7 8 9
        // 处理后，数字保持不变，下次取数会从4开始，因此相当于1和7倍删除了， 而整个数组需要长度要+1，多了一个下标10，去添加7

        int n1 = a[2*i];
        int n2 = a[2*i+1];
        cout << n1 << " ";
        a[n+i] = n2;
    }

    return 0;
}
