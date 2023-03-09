#include <bits/stdc++.h>


using namespace std;

/**
在桌面上有一排硬币，共N枚，每一枚硬币均为正面朝上。
现在要把所有的硬币翻转成反面朝上，规则是每次可翻转任意N-1枚硬币（正面向上的被翻转为反面向上，反之亦然）。
求一个最短的操作序列（将每次翻转N-1枚硬币成为一次操作）。
输入格式:
输入只有一行，包含一个自然数N（N为不大于100的偶数）。
输出格式:
输出文件的第一行包含一个整数S，表示最少需要的操作次数。
接下来的S行每行分别表示每次操作后桌上硬币的状态（一行包含N个整数（0或1），
表示每个硬币的状态：0——正面向上，和1——反面向上，不允许出现多余空格）。
对于有多种操作方案的情况，则只需输出一种。
限制:
对于100%的数据，1≤n≤100，1≤m≤100。
样例 1 :
输入:
4
输出:
4
0111
1100
0001
1111
 */
int N,ans;
struct Data {
    string s,prints;
    int step;
    vector<int> jl; // 剪枝用
};
queue<Data> q;
string ss,es;

bool find(int n, vector<int> &v)
{
    for (int i=0;i<v.size();i++) {
        if (n==v[i]) return true;
    }
    return false;
}
void bfs()
{
    while(!q.empty()) {
        Data d1=q.front();
        q.pop();
        if (d1.s==es) {
            cout << d1.step << "\n";
            cout << d1.prints;
            return;
        }
        for (int i=0;i<N;i++) {
            if (!find(i,d1.jl)) { // 剪枝，重复的下标不再选取
                d1.jl.push_back(i);
                string s2=d1.s;
                for (int j=0;j<N;j++) {
                    if (i!=j) {
                        if (s2[j]=='0') s2[j]='1';
                        else s2[j]='0';
                    }
                }
                string prints=d1.step==0?s2:d1.prints+"\n"+s2;
                Data d2={s2,prints,d1.step+1,d1.jl};
                q.push(d2);
            }
        }
    }
}

int main()
{
    cin >> N;
    // 思路：bfs解法
    // 初始字符串
    for (int i=0;i<N;i++) ss+='0';
    // 结束字符串
    for (int i=0;i<N;i++) es+='1';
    vector<int> jl1;
    Data d1=Data{ss,"",0,jl1};
    q.push(d1);
    bfs();
    return 0;
}
