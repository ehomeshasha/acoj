#include <iostream>
#include <math.h>
#include <algorithm>


using namespace std;

/**
生活大爆炸石头剪刀布
https://www.acoj.com/problems/12085

第一行包含三个整数:N,NA,NB,分别表示共进行 N 次猜拳、小 A 出拳的周期长度,
小 B 出拳的周期长度。数与数之间以一个空格分隔。
第二行包含 NA 个整数,表示小 A 出拳的规律,第三行包含 NB 个整数,表示小 B 出拳
的规律。其中,0 表示“剪刀”,1 表示“石头”,2 表示“布”,3 表示“蜥蜴人”, 4 表示 “斯波克”。数与数之间以一个空格分隔。
输出格式:

输出一行, 包含两个整数,以一个空格分隔,分别表示小 A、小 B 的得分。
限制:

对于100%的数据,0 < N  ≤  200, 0 < NA ≤ 200 , 0 < NB ≤ 200。
样例 1 :

输入:
10 5 6
0 1 2 3 4
0 3 4 2 1 0
输出:
6 2
样例 2 :

输入:
9 5 5
0 1 2 3 4
1 0 3 2 4
输出:
4 4
 */
int carr[5][2] = {
        {2,3},{0,3},{1,4},{2,4},{0,1}
};

int my_compare(int a, int b) {
    if (a==b)
        return 0;
    if(b==carr[a][0]||b==carr[a][1])
        return 1;
    return -1;
}


int main()
{
    int N, NA, NB;
    cin >> N >> NA >> NB;
    int a[205], b[205];
    int sa, sb;

    for (int i = 0; i < NA; i++)
        cin >> a[i];
    for (int i = 0; i < NB; i++)
        cin >> b[i];

    // 猜拳N次
    for (int i = 0; i < N; i++) {
        int res = my_compare(a[i%NA], b[i%NB]);
        // 结果为1， a胜， 结果为0，平局， 结果为-1 b胜
        if (res == 1)
            sa++;
        if (res == -1)
            sb++;
    }

    cout << sa << " " << sb << endl;
    return 0;
}
