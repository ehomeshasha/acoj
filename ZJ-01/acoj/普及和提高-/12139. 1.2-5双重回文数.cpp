#include <bits/stdc++.h>


using namespace std;

/**
如果一个数从左往右读和从右往左读都是一样，那么这个数就叫做“回文数”。例如，12321就是一个回文数，而77778就不是。
当然，回文数的首和尾都应是非零的，因此0220就不是回文数。
事实上，有一些数（如21），在十进制时不是回文数，但在其它进制（如二进制时为10101）时就是回文数。
编一个程序，从文件读入两个十进制数N (1 <= N <= 15)S (0 < S < 10000)
然后找出前N个满足大于S且在两种或两种以上进制（二进制至十进制）上是回文数的十进制数，输出到文件上。
本问题的解决方案不需要使用大于32位的整。

输入格式:

只有一行，用空格隔开的两个数N和S。
输出格式:

N行, 每行一个满足上述要求的数，并按从小到大的顺序输出.
样例 1 :

输入:
3 25
输出:
26
27
28
 */

bool is_hw(string s)
{
    for (int i=0;i<s.length()/2;i++) {
        if (s[i]!=s[s.length()-1-i]) return false;
    }
    return true;
}

string jz(int n, int B) // 二进制到十进制
{
    // 如果十进制直接返回
    if (B==10) return to_string(n);
    string s1,s2;
    for (int r=1;r<=n;r*=B) {
        s1+=n%(r*B)/r+'0';
    }
    // 倒序可以不用做，因为是后续是判断是否回文，正序逆序结果一致的
//    // 倒序
//    for (int i=s1.length()-1;i>=0;i--) {
//        s2+=s1[i];
//    }
    return s1;
}


int main()
{
    int N,S;
    cin >> N >> S;
    for (int n=S+1;N>0;n++) {
        // 回文数数量
        int hw_cnt=0;
        for (int B=10;B>=2;B--) {
            string s1=jz(n,B);
            if (is_hw(s1)) {
                hw_cnt++;
            }
            if (hw_cnt==2) {
                printf("%d\n",n);
                N--;
                break;
            }
        }
    }
    return 0;
}
