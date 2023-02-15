#include <bits/stdc++.h>


using namespace std;

/**
“xyzyx”是一个回文字符串，所谓回文字符串就是指正读反读均相同的字符序列，
 如“席主席”、“记书记”、“aha”和“ahaha”均是回文，但“ahah”不是回文。
 输入一行字符（仅包含小写英文字母a~z）请判断这行字符串是否为回文。
输入格式:
只有一行，仅包含小写英文字母a~z的字符串，长度小于等于100。
输出格式:
只有一行，如果是回文请输出YES，不是回文则输出NO，请注意大小写。
样例 1 :
输入:
ahah
输出:
NO
样例 2 :
输入:
ahaha
输出:
YES
 */

int main()
{
    string s;
    cin >> s;
    int l=s.length();
    for (int i=0;i<l/2;i++) {
        if (s[i]!=s[l-i-1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
