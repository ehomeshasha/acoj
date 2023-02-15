#include <bits/stdc++.h>


using namespace std;

/**
上课的时候总有一些同学和前后左右的人交头接耳，这是令小学班主任十分头疼的一件事情。
 不过，班主任小雪发现了一些有趣的现象，当同学们的座次确定下来之后，只有有限的D对同学上课时会交头接耳。
 同学们在教室中坐成了M行N列，坐在第i行第j列的同学的位置是（i，j），
 为了方便同学们进出，在教室中设置了K条横向的通道，L条纵向的通道。
 于是，聪明的小雪想到了一个办法，或许可以减少上课时学生交头接耳的问题：
 她打算重新摆放桌椅，改变同学们桌椅间通道的位置，因为如果一条通道隔开了两个会交头接耳的同学，那么他们就不会交头接耳了。
请你帮忙给小雪编写一个程序，给出最好的通道划分方案。在该方案下，上课时交头接耳的学生对数最少。
【输入输出样例】
seat.in	seat.out
4 5 1 2 3
4 2 4 3
2 3 3 3
2 5 2 4	2
2 4
输入输出样例解释
上图中用符号*、※、+标出了3对会交头接耳的学生的位置，图中3条粗线的位置表示通道，图示的通道划分方案是唯一的最佳方案。
输入格式:
输入的第一行，有5各用空格隔开的整数，分别是M，N，K，L，D（2 <= N，M <= 1000，0 <= K < M，0 <= L < N，D <= 2000）。
接下来D行，每行有4个用空格隔开的整数，第i行的4个整数Xi，Yi，Pi，Qi，表示坐在位置(Xi,Yi)与(Pi,Qi)的两个同学会交头接耳（输入保证他们前后相邻或者左右相邻）。
输入数据保证最优方案的唯一性。
输出格式:
输出两行。
第一行包含K个整数，a1a2……aK，表示第a1行和a1+1行之间、第a2行和第a2+1行之间、…、第aK行和第aK+1行之间要开辟通道，其中ai< ai+1，每两个整数之间用空格隔开（行尾没有空格）。
第二行包含L个整数，b1b2……bk，表示第b1列和b1+1列之间、第b2列和第b2+1列之间、…、第bL列和第bL+1列之间要开辟通道，其中bi< bi+1，每两个整数之间用空格隔开（行尾没有空格）。
提示:
NOIP普及组2008
限制:
各个测试点1s
样例 1 :
输入:
4 5 1 2 3
4 2 4 3
2 3 3 3
2 5 2 4
输出:
2
2 4
 */
struct XY {
    int zb;
    int cnt;
};

bool mysort(XY a, XY b)
{
    return a.cnt>b.cnt;
}

bool mysort2(XY a, XY b)
{
    return a.zb<b.zb;
}

int main()
{
    int M,N,K,L,D,xi,yi,pi,qi;
    XY xc[1005], yc[1005];
    cin >> M >> N >> K >> L >> D;
    // 初始化
    for (int i=0;i<1005;i++) {
        xc[i].cnt=0;xc[i].zb=0;
        yc[i].cnt=0;yc[i].zb=0;
    }
    for (int i=0;i<D;i++) {
        cin >> xi >> yi >> pi >> qi;
        if (xi==pi) { // 横向排列，交头接耳
            int min_v=min(yi,qi); // 取最小值
            yc[min_v].cnt++;yc[min_v].zb=min_v;
        } else if (yi==qi) { // 同理
            int min_v=min(xi,pi);
            xc[min_v].cnt++;xc[min_v].zb=min_v;
        }
    }
    // 先降序排序, 数组为能够切分最大坐标降序
    sort(xc,xc+1005, mysort);
    sort(yc,yc+1005, mysort);
    // 再升序排序前K/L个，满足输出要求
    sort(xc,xc+K, mysort2);
    sort(yc,yc+L, mysort2);

    // 贪心算法
    for (int i=0;i<K;i++) {
        // 每次取数组头元素， 最大的那个
        printf("%d", xc[i].zb);
        if (i!=K-1) printf(" ");
    }
    printf("\n");
    for (int i=0;i<L;i++) {
        // 每次取数组头元素， 最大的那个
        printf("%d", yc[i].zb);
        if (i!=L-1) printf(" ");
    }
    return 0;
}
