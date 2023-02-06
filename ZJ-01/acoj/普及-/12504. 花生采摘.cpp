#include <bits/stdc++.h>


using namespace std;

/**
鲁宾逊先生有一只宠物猴，名叫多多。这天，他们两个正沿着乡间小路散步，突然发现路边的告示牌上贴着一张小小的纸条：“欢迎免费品尝我种的花生！――熊字”。
鲁宾逊先生和多多都很开心，因为花生正是他们的最爱。在告示牌背后，路边真的有一块花生田，花生植株整齐地排列成矩形网格（如图1）。有经验的多多一眼就能看出，每棵花生植株下的花生有多少。为了训练多多的算术，鲁宾逊先生说：“你先找出花生最多的植株，去采摘它的花生；然后再找出剩下的植株里花生最多的，去采摘它的花生；依此类推，不过你一定要在我限定的时间内回到路边。”




我们假定多多在每个单位时间内，可以做下列四件事情中的一件：

从路边跳到最靠近路边（即第一行）的某棵花生植株；
从一棵植株跳到前后左右与之相邻的另一棵植株；
采摘一棵植株下的花生；
从最靠近路边（即第一行）的某棵花生植株跳回路边。
现在给定一块花生田的大小和花生的分布，请问在限定时间内，多多最多可以采到多少个花生？注意可能只有部分植株下面长有花生，假设这些植株下的花生个数各不相同。
例如在图2所示的花生田里，只有位于(2, 5), (3, 7), (4, 2), (5, 4)的植株下长有花生，个数分别为13, 7, 15, 9。沿着图示的路线，多多在21个单位时间内，最多可以采到37个花生。
输入格式:

第一行包括三个整数，M, N和K，用空格隔开；表示花生田的大小为M * N（1 <= M, N <= 20），多多采花生的限定时间为K（0 <= K <= 1000）个单位时间。接下来的M行，每行包括N个非负整数，也用空格隔开；第i + 1行的第j个整数Pij（0 <= Pij <= 500）表示花生田里植株(i, j)下花生的数目，0表示该植株下没有花生。
输出格式:

一个整数，即在限定时间内，多多最多可以采到花生的个数。
样例 1 :

输入:
6 7 21
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
输出:
37
样例 2 :

输入:
6 7 20
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
输出:
28
 */

int mysort(int* a, int* b)
{
    return a[0] > b[0];
}

int main()
{
    int M,N,K,time=0,cnt=0;
    cin >> M >> N >> K;
    vector<int*> d;
    for (int x=1;x<=M;x++) {
        for (int y=1;y<=N;y++) {
            int tmp;
            cin >> tmp;
            if (tmp>0) {
                int *zw = new int[3];
                zw[0]=tmp;zw[1]=x;zw[2]=y;
                d.push_back(zw);
            }
        }
    }
    // 排序
    sort(d.begin(), d.end(), mysort);

    for (int i=0;i<d.size();i++) {
        int move;
        int back;
        int caizai=1;
        if (i==0) {
            move=d[i][1]; // move
            back=d[i][1]; // back
        } else {
            move= abs(d[i][1] - d[i-1][1]) + abs(d[i][2] - d[i-1][2]); // move
            back=d[i][1]; // back
        }
        // 先尝试采摘，判断时间是否大于K，如果大于就不能继续采摘了
        // 否则可以采摘， 时间增加， cnt增加
        if (time+move+caizai+back>K) break;
        time+=move+caizai;
        cnt+=d[i][0];
    }
    cout << cnt << endl;
    return 0;
}
