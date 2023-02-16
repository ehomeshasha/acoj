#include <bits/stdc++.h>


using namespace std;

/**
小哼和小哈一同坐飞机去旅游，他们现在位于1号城市，目标是5号城市，可是1号城市并没有到5号城市的直航。
 不过小哼已经收集了很多航班的信息，现在小哼希望找到一种乘坐方式，使得转机的次数最少，如何解决呢？
输入格式:
第一行的有两个整数n m s e，n表示有n个城市（城市编号为1~n），m表示有m条航线，s表示起点城市，e表示目标城市。
接下来m行每行是一条类似“a b”这样的数据表示城市a和城市b之间有航线，也就是说城市a和城市b之间可以相互到达
输出格式:
s号城市到e号目标城市，需要飞行几次？
限制:
1<=n<=1000
1<=m<=300000
样例 1 :
输入:
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
输出:
2
 */
const int N=1000005;
int n,m,s,e,visit[1005];
vector<int> v1[1005];
struct Trip {
    int city;
    int step;
};
Trip cities[N];
struct Queue {
    int head;
    int tail;
    Trip* cities;
} q{0,0,cities};
void enQueue(int city, int step)
{
    q.cities[q.tail++]=Trip{city,step};
}
Trip deQueue()
{
    return q.cities[q.head++];
}

void bfs()
{
    while(q.head!=q.tail) { // 队列里面有数据， 开始遍历
        Trip trip=deQueue();
        if (trip.city==e) { // 到达目的城市， 此时的解就是最短路径
            cout << trip.step;
            return;
        }
        for (int i=0;i<v1[trip.city].size();i++) { // 遍历所有能到达的城市，压入队列
            // 去掉回头路
            if (visit[v1[trip.city][i]]==0) {
                visit[v1[trip.city][i]]=1;
                enQueue(v1[trip.city][i], trip.step+1);
            }
        }
    }
}

int main()
{
    int t1,t2;
    scanf("%d %d %d %d\n",&n,&m,&s,&e);
    for (int i=0;i<m;i++) {
        scanf("%d %d\n",&t1,&t2);
        v1[t1].push_back(t2);
        v1[t2].push_back(t1);
    }
    // bfs遍历
    enQueue(s,0); // 开始城市压入队列
    bfs();
    return 0;
}
