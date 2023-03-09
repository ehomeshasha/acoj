#include <bits/stdc++.h>


using namespace std;

/**
有一天，小明学会了加减法，便爱上了做等式计算，诸如a+b或者a-b之类的问题。但是貌似一般的加减法计算难不倒小明。
终于，小明的老师想到一个考验小明的办法：让他算a+?=b或 ?+a=b 或 a+b=?。
这回小明不会做了，于是找到了你。注明只会出现加减运算。
输入格式:

输入一个等式，形如a+b=c或a-b=c。给定其中的两个数，请确定其中的第三个数。
其中0<=A,B,C<1,000,000,000，没有给定的数用一个单独的“？”表示，等式中没有多余空格。
输出格式:
直接输出要求的第三个数。
限制:
0<=A,B,C<1,000,000,000
样例 1 :
输入:
1+2=?
输出:
3
样例 2 :
输入:
15+?=115
输出:
100
 */

int main()
{
    // 记得最后换成long long
    string s;
    cin >> s;
    int mode=0;
    int idx1=s.find('+');
    if (idx1!=-1) mode=1;
    else idx1=s.find('-');
    int idx2=s.find('=');
    string sa=s.substr(0,idx1);
    string sb=s.substr(idx1+1,idx2-idx1-1);
    string sc=s.substr(idx2+1,s.length()-idx2-1);
    int ans,a,b,c;
    // 判断第一个是不是等号
    if (sa=="?") { // ?+b=c
        b=stoi(sb),c=stoi(sc);
        ans=mode==1?c-b:c+b;
    } else if (sc=="?") { // a+b=?
        a=stoi(sa),b=stoi(sb);
        ans=mode==1?a+b:a-b;
    } else { // a+?=c
        a=stoi(sa),c=stoi(sc);
        ans=mode==1?c-a:a-c;
    }
    cout << ans;
    return 0;
}
