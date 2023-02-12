#include <bits/stdc++.h>


using namespace std;

/**
输入一个二进制的数，输出该数对应的八进制数字。
输入格式:
输入一行，一个二进制数字，数字长度不超过100位。
输出格式:
输出一行，一个八进制数字。
限制:
二进制数字不超过100位
样例 1 :
输入:
11
输出:
3
样例 2 :
输入:
101
输出:
5
样例 3 :
输入:
1001
输出:
11
 */

map<string,string> m;
void init_m()
{
    m["0"]="0";
    m["1"]="1";
    m["10"]="2";
    m["11"]="3";
    m["000"]="0";
    m["001"]="1";
    m["010"]="2";
    m["011"]="3";
    m["100"]="4";
    m["101"]="5";
    m["110"]="6";
    m["111"]="7";
}

int main()
{
    string s2,res="";
    cin >> s2;
    init_m();
    int s2_len = s2.length();
    int start_pos,n;
    int spl=s2_len%3;
    spl=spl!=0?spl-3:0;
    for (int i=spl;i<s2_len;i+=3) {
        if (i>0) {
            start_pos=i;n=3;
        } else {
            start_pos=0;n=i+3;
        }
        res+=m[s2.substr(start_pos,n)];
    }
    cout << res;
    return 0;
}
