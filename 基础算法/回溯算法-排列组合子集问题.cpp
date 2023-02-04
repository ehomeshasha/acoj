#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
Zeratul有一些不同长度的编号为1~n的火柴棒，他想知道手中的火柴棒能够组成的三角形中，周长最大的是多少。
输入格式:
第一行包括一个整数n，代表火柴棒的数量。
第二行包括n个整数，代表每个火柴棒的长度。
输出格式:
一个整数，代表周长的最大值。如果Zeratul的火柴棒无法组成任何的三角形，输出-1。
限制:
对于100%的数据，n<=100,每个火柴棒的长度<=100000。
样例 1 :
输入:
4
1 2 3 4
输出:
9
样例 2 :
输入:
4
1 2 4 8
输出:
-1
 */
int result[200000][3],n,a[101]={0},result_len,path[3]={0},max_zhouchang=0;
int mylen(int *path) {
    int len=0;
    for (int i=0;i<3;i++)
        if (path[i]!=0)
            len++;
    return len;
}
void myprint(int *path) {
    for (int i=0;i<3;i++)
        cout << path[i] << " ";
    cout << endl;
}
int mycontain(int n, int* path) {
    for (int i=0;i<3;i++)
        if (n==path[i]) return 1;
    return 0;
}
int find(int* path) {
    for (int i=0;i<result_len;i++) {
        int* re=result[i];
        int c=0;
        for (int j=0;j<3;j++) {
            for (int k=0;k<3;k++) {
                if (re[j]==path[k]) {
                    c++;
                    break;
                }
            }
        }
        if (c==3) return 1;
    }
    return 0;
}
// 回溯算法
void trace(int* path) {
    int pl = mylen(path);
    // 结束条件
    if (pl==3) {
        // 判断是否已经存在， 如果存在则不加入数组
        if(find(path)==0) {
            result[result_len][0] = path[0];
            result[result_len][1] = path[1];
            result[result_len][2] = path[2];
            result_len++;
        }
        path[pl-1]=0;
        return;
    }
    // 已经在path里面的元素需要从a中过滤掉再遍历
    for (int j=1;j<=n;j++) {
        // 如果在path里面就过滤
        if (mycontain(a[j], path)==1) continue; // 剪纸条件
        path[pl]=a[j];
        trace(path);
        path[pl]=0; // 回溯操作
    }
}

int main()
{
    // 回溯算法 - ?分
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    // 组合问题
    trace(path);

    return 0;
}
