#include <bits/stdc++.h>


using namespace std;

/**
农民约翰的母牛总是产生最好的肋骨。 你能通过农民约翰和美国农业部标记在每根肋骨上的数字认出它们。 农民约翰确定他卖给买方的是真正的质数肋骨,是因为从右边开始切下肋骨,每次还剩下的肋骨上的数字都组成一个质数,举例来说: 7 3 3 1 全部肋骨上的数字 7331是质数;三根肋骨 733是质数;二根肋骨 73 是质数;当然,最后一根肋骨 7 也是质数。 7331 被叫做长度 4 的特殊质数。 写一个程序对给定的肋骨的数目 N (1<=N<=8),求出所有的特殊质数。 数字1不被看作一个质数。

输入格式:

单独的一行包含N。
输出格式:

按顺序输出长度为 N 的特殊质数,每行一个。
样例 1 :

输入:
4
输出:
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393
 */
int N,n1[4]={2,3,5,7};
bool isprime(int n)
{
    if (n==0||n==1) return false;
    if (n==2) return true;
    int t=sqrt(n);
    for (int i=2;i<=t;i++) {
        if (n%i==0) return false;
    }
    return true;
}
void trace(int step, string &s)
{
    int n;
    if (step>0) {
        n=stoi(s);
        if (!isprime(n)) return;
    }
    if (step==N) {
        printf("%d\n",n);
        return;
    }
    if (step==0) {
        for (int i=0;i<4;i++) {
            s+=n1[i]+'0';
            trace(step+1,s);
            s=s.substr(0,s.length()-1);
        }
    } else {
        for (int i=1;i<=9;i+=2) {
            s+=i+'0';
            trace(step+1,s);
            s=s.substr(0,s.length()-1);
        }
    }
}

int main()
{
    cin >> N;
    string s;
    trace(0,s);
    return 0;
}
