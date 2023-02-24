#include <bits/stdc++.h>


using namespace std;

/**
键盘输入一个正整数 n(≤300 位)， 去掉其中任意 s 个数字后剩下的数字按原左右次序将组成一个新的正整数。
 编程对给定的 n 和 s， 寻找一种方案， 使得剩下的数字组成的新数最小。

输入格式:

有两行
第一行为一个整数 n
第二行为一个整数 s
输出格式:

最后剩下的最小数
样例 1 :

输入:
178543
4
输出:
13
样例 2 :

输入:
1234567890123456789
1
输出:
123456780123456789
 */

int main()
{
    // 要使其最小，需要遍历一遍删除掉第一个向上的峰值（峰值可以在初始位置）
    // 先求出最大数字， 然后从左往右删第一个
    string s1;
    int n;
    cin >> s1 >> n;
    for (int i=0;i<n;i++) {
        if (s1.length()==0) {
            cout << 0;
            return 0;
        }
        int lastn=s1[0]-'0',maxn=lastn;
        for (int j=1;j<s1.length();j++) {
            int nown=s1[j]-'0';
            if (nown>=lastn) {
                maxn=nown;
                lastn=nown;
            }
            else break;
        }
        int pos=s1.find(maxn+'0');
        s1.erase(pos,1);
        if (s1.length()==0) { // 删完的情况
            cout << 0;
            return 0;
        }
    }
    // 去掉前导0
    int no_zero_idx=0;
    for (int i=0;i<s1.length();i++) {
        if (s1[i]!='0') {
            no_zero_idx=i;
            break;
        }
    }
    if (no_zero_idx!=0) s1=s1.substr(no_zero_idx, s1.length()-no_zero_idx);
    cout << s1;
    return 0;
}
