#include <bits/stdc++.h>


using namespace std;

/**
回文数是指从左向右念和从右向左念都一样的数。如12321就是一个典型的回文数。
给定一个进制B(2<=B<=20,由十进制表示)，输出所有的大于等于1小于等于300（十进制下）且它的平方用B进制表示时是回文数的数。用’A’,’B’……表示10，11等等。
输入格式:
共一行，一个单独的整数B(B用十进制表示)。
输出格式:
每行两个B进制的符合要求的数字，第二个数是第一个数的平方，且第二个数是回文数.
样例 1 :
输入:
10
输出:
1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696

 */
char zhuanhuan(int n) // 10->a
{
    if (n<10) return n+'0';
    else return n-10+'A';
}

string Bjinzhi(int n, int B) // 输入为10进制的数字， 输出为B进制的字符串
{
    string s="",s1="";
    for (int r=1;r<=n;r*=B) {
        s+=zhuanhuan(n%(B*r)/r);
    }
    // 倒序一下
    for (int i=s.length()-1;i>=0;i--) {
        s1+=s[i];
    }
    return s1;
}

bool is_huiwen(string s)
{
    for (int i=0;i<s.length()/2;i++) {
        if (s[i]!=s[s.length()-1-i]) return false;
    }
    return true;
}

int main()
{
    int B;
    cin >> B;
    for (int i=1;i<=300;i++) {
        // i转换为B进制
        // 对i进行平方， i^2转换成B进制
        // 判断i^2的B进制是否是回文数
        // 如果是就打印B进制下的i和i^2
        // 否则continue跳过继续
        int b=i*i;
        string bb=Bjinzhi(b,B);
        if(is_huiwen(bb)) {
            printf("%s %s\n", Bjinzhi(i,B).c_str(), bb.c_str());
        }
    }

    return 0;
}
