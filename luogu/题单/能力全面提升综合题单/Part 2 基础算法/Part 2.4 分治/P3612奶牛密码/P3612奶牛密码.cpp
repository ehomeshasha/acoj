#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P3612
N<=10^18
L<=30
 */
#define int long long
// 快速幂算法
int ksm(int a, int b)
{
    int res=1;
    while(b!=0) {
        if (b%2==1) res=res*a;
        a=a*a;
        b=b/2;
    }
    return res;
}

int calRepeat(int N, int L)
{
    int n=L,repeat=0;
    while(n<N) {
        repeat++;
        n=n*2;
    }
    return repeat;
}

char solve(string s, int L, int N, int R)
{
    if (R==0) return s[N-1];
    int half=ksm(2,R)/2*L;
    int i=N-half; // 右侧的位置，从1开始
    if (i<=0) { // 在左侧
        return solve(s,L,N,R-1);
    }
    // 如果i=1，那么就是左侧字符串最后一个
    // 如果i=2，是第一个
    // 如果i=3，是第二个，以此类推
    if (i==1) return solve(s,L,half,R-1);
    else return solve(s,L,i-1,R-1);
}
#undef int
int main()
#define int long long
{
    // 给定N，可以计算出要翻转多少次
    // 假如字符串长度为L, 翻转一次L*2, 翻转两次L*2*2, 翻转n次就是L*2^n
    // 已知2^64次一定比N大，那么n介于0~64之间
    // 计算出需要的最小n值
    // 求位置N的字符问题可以变为
    string s;
    int N,L,R;
    cin >> s >> N;
    L=s.length();
    R=calRepeat(N,L);
    char c=solve(s,L,N,R);
    cout << c;
    return 0;
}
