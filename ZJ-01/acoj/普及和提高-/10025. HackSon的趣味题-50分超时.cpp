#include <bits/stdc++.h>


using namespace std;

/**
Hanks 博士是BT (Bio-Tech，生物技术) 领域的知名专家，他的儿子名叫Hankson。现在，刚刚放学回家的Hankson 正在思考一个有趣的问题。
今天在课堂上，老师讲解了如何求两个正整数c1 和c2 的最大公约数和最小公倍数。现在Hankson 认为自己已经熟练地掌握了这些知识，
 他开始思考一个“求公约数”和“求公倍数”之类问题的“逆问题”，这个问题是这样的：已知正整数a0,a1,b0,b1，设某未知正整数x 满足：
1． x 和a0 的最大公约数是a1；
2． x 和b0 的最小公倍数是b1。
Hankson 的“逆问题”就是求出满足条件的正整数x。但稍加思索之后，他发现这样的x 并不唯一，甚至可能不存在。因此他转而开始考虑如何求解满足条件的x 的个数。请你帮助他编程求解这个问题。
输入格式:
第一行为一个正整数n，表示有n 组输入数据。
接下来的n 行每行一组输入数据，为四个正整数a0，a1，b0，b1，每两个整数之间用一个空格隔开。
输入数据保证a0 能被a1 整除，b1 能被b0 整除。
输出格式:
共n 行。每组输入数据的输出结果占一行，为一个整数。
对于每组数据：若不存在这样的 x，请输出 0；
若存在这样的 x，请输出满足条件的 x 的个数；
提示:
NOIP 2009
限制:
每个测试点1s
对于 50%的数据，保证有1≤a0，a1，b0，b1≤10000 且n≤100。
对于 100%的数据，保证有1≤a0，a1，b0，b1≤2,000,000,000 且n≤2000。
样例 1 :
输入:
2
41 1 96 288
95 1 37 1776
输出:
6
2
说明:
第一组输入数据，x 可以是9、18、36、72、144、288，共有6 个。
第二组输入数据，x 可以是48、1776，共有2 个。
若存在这样的 x，请输出满足条件的x 的个数；
 */

long long gcd(long long a, long long b) // a为长边，b为短边
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}

long long lcm(long long a, long long b)
{
    long long max_ys=gcd(a,b);
    return a/max_ys*b;
}

int main()
{
    long long n,a0,a1,b0,b1;
    cin >> n;
    for (long long i=0;i<n;i++) {
        int cnt=0;
        cin >> a0 >> a1 >> b0 >> b1;
        for (long long x=a1;x<=b1;x+=a1) {
            long long max_ys=gcd(a0,x);
            if (max_ys!=a1) continue;
            long long min_bs=lcm(b0,x);
            if (min_bs!=b1) continue;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
