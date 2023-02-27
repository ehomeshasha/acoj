#include <bits/stdc++.h>


using namespace std;

/**
因为151既是一个质数又是一个回文数(从左到右和从右到左是看一样的)，所以 151 是回文质数。
写一个程序来找出范围[a,b](5 <= a < b <= 100,000,000)( 一亿)间的所有回文质数;
输入格式:
第 1 行: 二个整数 a 和 b .
输出格式:
输出一个回文质数的列表，一行一个。
提示:
Hint 1: Generate the palindromes and see if they are prime.
 提示 1: 找出所有的回文数再判断它们是不是质数（素数）.
Hint 2: Generate palindromes by combining digits properly.
 You might need more than one of the loops like below. 提示
 2: 要产生正确的回文数，你可能需要几个像下面这样的循环。
产生长度为5的回文数: C++:
 for (d1 = 1; d1 <= 9; d1+=2) {	// 只有奇数才会是素数
     for (d2 = 0; d2 <= 9; d2++) {
         for (d3 = 0; d3 <= 9; d3++) {
           palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;//(处理回文数...)
         }
     }
 }
样例 1 :
输入:
5 500
输出:
5
7
11
101
131
151
181
191
313
353
373
383
 */
int a,b,minl,maxl;
int ans=0;
// 求数字的位数
int mlen(int n)
{
    int l=0;
    for(int r=1;r<=n;r*=10) {
        l++;
    }
    return l;
}
bool isprime(int n)
{
    if (n==2) return true;
    int t=sqrt(n);
    for (int i=2;i<=t;i++) {
        if (n%i==0) return false;
    }
    return true;
}
void dfs(int step, int half_len, int len, string &s)
{
    if (step==half_len) {
        // 判断是不是回文质数
        string s2;
        for (int i=0;i<s.length();i++) s2+=s[i];
        if (len%2==0) for (int i=s.length()-1;i>=0;i--) s2+=s[i];
        else for (int i=s.length()-2;i>=0;i--) s2+=s[i];
        int n2=stoi(s2);
        if (isprime(n2)&&n2>=a&&n2<=b) { // 质数且要再ab之间
            ans++;
            printf("%d\n", n2);
        }
//        ans++;

        // 求s2是不是质数

        return;
    }
    if (step==0) {
        for (int i=1;i<=9;i+=2) {
            s+=i+'0';
            dfs(step+1,half_len,len,s);
            s=s.substr(0,s.length()-1);
        }
    } else {
        for (int i=0;i<=9;i++) {
            s+=i+'0';
            dfs(step+1,half_len,len,s);
            s=s.substr(0,s.length()-1);
        }
    }

}

int main()
{
    // 思路从少的位数到大的位数， 最多8位，因为1亿不是回文质数
    cin >> a >> b;
    minl=mlen(a),maxl=min(mlen(b),8);
//    string s1;
//    dfs(0,1,s1);
    for (int i=minl;i<=maxl;i++) { // 遍历可能的位数
        // 1位数 number=d1*10^0 d1
        // 2位数 number=d1*10^1+d1*10^0 d1
        // 3位数 number=d1*10^2+d2*10^1+d1*10^0 d1,d2
        // 4位数 number=d1*10^3+d2*10^2+d2*10^1+d1*10^0 d1,d2
        // 5位数 number=d1*10^4+d2*10^3+d3*10^2+d2*10^1+d1*10^0 d1,d2,d3
        // 6位数 number=d1*10^5+d2*10^4+d3*10^3+d3*10^2+d2*10^1+d1*10^0 d1,d2,d3
        // 7位数 number=d1*10^6+d2*10^5+d3*10^4+d4*10^3+d3*10^2+d2*10^1+d1*10^0 d1,d2,d3,d4
        // 8位数 number=d1*10^7+d2*10^6+d3*10^5+d4*10^4+d4*10^3+d3*10^2+d2*10^1+d1*10^0 d1,d2,d3,d4
        // 需要的变量数量为(i+1)/2
        string s1;
        int half_len=(i+1)/2; // 求len的全排列，其中第一个数要是奇数
        dfs(0,half_len,i,s1);
    }
//    cout << ans;
    return 0;
}
