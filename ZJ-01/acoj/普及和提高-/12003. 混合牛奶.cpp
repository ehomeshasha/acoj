#include <bits/stdc++.h>


using namespace std;

/**
由于乳制品产业利润很低，所以降低原材料（牛奶）价格就变得十分重要。帮助Marry乳业找到最优的牛奶采购方案。
Marry乳业从一些奶农手中采购牛奶，并且每一位奶农为乳制品加工企业提供的价格是不同的。
 此外，就像每头奶牛每天只能挤出固定数量的奶，每位奶农每天能提供的牛奶数量是一定的。
 每天Marry乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。
给出Marry乳业每天对牛奶的需求量，还有每位奶农提供的牛奶单价和产量。计算采购足够数量的牛奶所需的最小花费。
注：每天所有奶农的总产量大于Marry乳业的需求量。
输入格式:
第 1 行共二个数值:N,(0<=N<=2,000,000)是需要牛奶的总数；M,(0<= M<=5,000)是提供牛奶的农民个数。
第 2 到 M+1 行:每行二个整数:Pi 和 Ai。
Pi(0<= Pi<=1,000) 是农民 i 的牛奶的单价。
Ai(0 <= Ai <= 2,000,000)是农民 i 一天能卖给Marry的牛奶制造公司的牛奶数量。
输出格式:
单独的一行包含单独的一个整数，表示Marry的牛奶制造公司拿到所需的牛奶所要的最小费用
提示:
USACO Training
限制:
每个测试点1秒
样例 1 :
输入:
100 5
5 20
9 40
3 10
8 80
6 30
输出:
630
 */
// 打表
int N,M,sum=0;
struct Good {
    int price;
    int amount;
};
Good goods[5005];

bool mysort(Good a, Good b)
{
    return a.price<b.price;
}

int main()
{
    cin >> N >> M;
    // 背包问题， 装满背包且成本最小，
    // 思路： 从最小单价开始装，直到装满为止
    for (int i=0;i<M;i++) {
        cin >> goods[i].price >> goods[i].amount;
    }
    sort(goods, goods+M, mysort);
    for (int i=0;i<M;i++) {
        if (N==0) break; // 背包装满了，退出循环
        int v=min(N,goods[i].amount);
        sum+=goods[i].price*v;
        N-=v;
    }
    cout << sum;
    return 0;
}
