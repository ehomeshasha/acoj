#include <bits/stdc++.h>


using namespace std;

/**
林克计划败露企图逃跑，在数据世界中，林克逃跑只能使用步行或者传送，
 林克当前处于一个一维坐标系中某点x，每一秒钟他可以步行可以往前走一步即到达x+1，也可以往后走一步即达到x-1，
 或者使用传送，可以直接传送到2x的位置。林克的起始点为S，他必须跑到K点才能逃脱。
 例如林克目前在5，目标点在17，他可以先传送到达10，再往回走一步到达9，在传送到达18，最后再往回走一步达到17，这样5-10-9-18-17，只需要4秒钟。
输入格式:
只有一行包含两个整数S和K
输出格式:
输出一个整数，表示林克最快几秒钟可以达到K点。
限制:
0<=S<=100000
0<=K<=100000
样例 1 :
输入:
5 17
输出:
4
说明:
5-10-9-18-17,需要4秒钟。
 */
const int N=100005;
struct Data {
    int n;
    int step;
} dd[N];
struct Queue {
    int head;
    int tail;
    Data *arr;
} q={0,0,dd};
int visit[9000005]={0};

void enQueue(Data &d)
{
    q.arr[q.tail]=d;
    q.tail=(q.tail+1)%N;
}
Data deQueue()
{
    Data d=q.arr[q.head];
    q.head=(q.head+1)%N;
    return d;
}
int S,K;

void bfs()
{
    while(q.head!=q.tail) {
        Data d=deQueue();
        if (d.n==K) {
            // 到达终点
            cout << d.step;
            return;
        }
        vector<int> v1;
        if (d.n>K) {
            v1.push_back(d.n-1);
        } else if (d.n<0) {
            v1.push_back(d.n+1);
            v1.push_back(d.n*2);
        } else {
            v1.push_back(d.n-1);
            v1.push_back(d.n+1);
            v1.push_back(d.n*2);
        }
        // 剔除不可能方向
        for (int i=0;i<v1.size();i++) {
            if (visit[v1[i]]==0&&v1[i]>0 && v1[i]<=100005) {
                visit[v1[i]]=1;
                Data d1=Data {v1[i],d.step+1};
                enQueue(d1);
            }
        }
    }
}
int main()
{
    // 最短路径问题
    // 每次都有3个可能性，遍历加入队列
    cin >> S >> K;
    Data d=Data {S,0};
    visit[S]=1;
    enQueue(d);
    bfs();
    return 0;
}
