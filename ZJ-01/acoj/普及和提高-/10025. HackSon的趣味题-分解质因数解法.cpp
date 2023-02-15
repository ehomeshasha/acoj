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
int n,a0,a1,b0,b1;
int pm_idx=0,p_flag[45000],pm[45000],N=45000;
// 欧氏筛
void create_pm()
{
    for (int i=2;i<=N;i++) {
        if (p_flag[i]==0) pm[pm_idx++]=i;
        for (int j=0;j<pm_idx&&i*pm[j]<N;j++) {
            p_flag[i*pm[j]]=1;
            if (i%pm[j]==0) break;
        }
    }
}

int cal(int p)
{
    int a0m=0,a1m=0,b0m=0,b1m=0;
    while(a0%p==0) {a0/=p;a0m++;}
    while(a1%p==0) {a1/=p;a1m++;}
    while(b0%p==0) {b0/=p;b0m++;}
    while(b1%p==0) {b1/=p;b1m++;}
    // 已知a1m=min(a0m,r), b1m=max(b0m,r)
    // if (a1m<a0m) r=a1m;
    // else if (a1m==a0m) r>=a0m; 解范围是[a0m,
    // else if (a1m>a0m) // 无解， 直接跳出
    // if (b1m<b0m) // 无解直接跳出
    // else if (b1m==b0m) r<=b0m; 解范围是[,b0m]
    // else if (b1m>b0m) r=b1m
    // 综上解范围是[a0m,b0m]或r=a1m且<=b0m或r=b1m且>=a0m或r==a1m==b1m
    // 全部解个数用乘法原理相乘即可
    if (a1m>a0m||b1m<b0m) {
        return 0; // 无解
    }
    if (a1m==a0m) { // 解范围是[a0m,
        if (b1m==b0m) { // 解范围是[,b0m]
            int scope=b0m-a0m+1; // [a0m,b0m]
            if (scope<1) return 0; // 无解
            else return scope;
        } else if (b1m>b0m) {
            if (b1m>=a0m) return 1; // r=b1m且满足解范围[a0m,
            else return 0; // 无解
        }
    } else if (a1m<a0m) { // 解r=a1m
        if (b1m==b0m) { // 解范围是[,b0m]
            if (a1m<=b0m) return 1;// 满足解r=a1m且解范围是[,b0m]
            else return 0; // 无解
        } else if (b1m>b0m) { // 解r=b1m
            if (a1m==b1m) return 1; // 同时满足r=a1m, r=b1m
            else return 0; // 无解
        }
    }
    return 0;
}


int main()
{
    /**
     * 1. 打质数表， 因为超过根号n的只有1个质因数，因此只打根号n内的质因数表，后面再补
     * 2. 对于a0,a1,b0,b1遍历所有质因数（质因数平方要小于a0,b1的max），求x对每个质因数的范围
     * 3. 补上可能漏的质因数（针对可能的a0和b1）
     */
    cin >> n;
    create_pm();
    for (int i=0;i<n;i++) {
        int cnt=1;
        cin >> a0 >> a1 >> b0 >> b1;
        // 对每个数进行求解
        // 遍历所有根号n内所有可能的质因数, 求出幂值
        for (int j=0;j<pm_idx&&pm[j]*pm[j]<=max(a0,b1);j++) {
            int p=pm[j];
            // 求出a0,a1,b0,b1的pm次幂
            int cnt1=cal(p);
            cnt*=cnt1;
            if (cnt1==0) break;
        }
        // 如果a0或b1除不尽，说明遗漏了大于根号n的质因数，这个唯一的质因数就是a0，再用这个唯一的质因数算一遍
        if (a0>1) cnt*=cal(a0);
        if (b1>1) cnt*=cal(b1);
        printf("%d\n",cnt);
    }
    return 0;
}
