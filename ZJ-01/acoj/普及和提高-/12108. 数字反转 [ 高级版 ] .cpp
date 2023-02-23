#include <bits/stdc++.h>


using namespace std;

/**
给定一个整数N，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，
 否则反转后得到的新数的最高位数字不应为零
输入格式:
输入共1 行，一个整数N。
输出格式:
输出共1 行，一个整数，表示反转后的新数。
限制:
N的位数不超过10000位
样例 1 :
输入:
-100
输出:
-1
样例 2 :
输入:
123456789123456789123456789
输出:
987654321987654321987654321
 */

int main()
{
    string s1,s2;
    int end_i=0,no_zero_idx=0;
    cin >> s1;
    if (s1[0]=='-') end_i=1;

    for (int i=s1.length()-1;i>=end_i;i--) {
        s2+=s1[i];
    }
    for (int i=0;i<s2.length();i++) {
        if (s2[i]!='0') {
            no_zero_idx=i;
            break;
        }
    }
    s2=s2.substr(no_zero_idx, s2.length()-no_zero_idx);
    if (s1[0]=='-') s2='-'+s2;
    cout << s2;
    return 0;
}
