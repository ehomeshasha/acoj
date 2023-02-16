#include <bits/stdc++.h>


using namespace std;

/**
输入一个自然数N（1<=N<=9），从小到大输出用1~N组成的所有排列，也就说全排列。例如输入3则输出
123
132
213
231
312
321
输入格式:
输入一个自然数N（1<=N<=9）
输出格式:
N的全排列，每行一个
限制:
每个测试点1秒
样例 1 :
输入:
2
输出:
12
21
样例 2 :
输入:
3
输出:
123
132
213
231
312
321
 */
int N,path[9]={0};

int mplen() // path数组是递增写入
{
    int l=0;
    for (int i=0;i<9;i++) {
        if (path[i]!=0) l++;
        else break; // 遇到0停止
    }
    return l;
}
void mprint()
{
    for (int i=0;i<N;i++) {
        printf("%d",path[i]);
    }
    printf("\n");
}
bool mfind(int n, int plen)
{
    for (int i=0;i<plen;i++) {
        if (n==path[i]) return true;
    }
    return false;
}
void mtrace(int plen)
{
    if (plen==N) {
        // 已经找到所有元素, 打印
        mprint();
        return;
    }
    for (int i=1;i<=N;i++) {
        if (mfind(i,plen)) continue;
        path[plen]=i;
        mtrace(plen+1);
        path[plen]=0; // 回溯
    }

}

int main()
{
    // 全排列问题
    // 回溯算法 - dfs变种
    // 遍历解空间
    cin >> N;
    // 1~N
    mtrace(0);

    return 0;
}
