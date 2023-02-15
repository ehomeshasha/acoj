#include <bits/stdc++.h>


using namespace std;

/**
回文数是指从左向右念和从右向左念都一样的数。如12321就是一个典型的回文数。
给定一个进制B(2<=B<=20,由十进制表示)，输出所有的大于等于1小于等于300（十进制下）且它的平方用B进制表示时是回文数的数。
用’A’,’B’……表示10，11等等。
输入格式:
共一行，一个单独的整数B(B用十进制表示)。
输出格式:
每行两个B进制的符合要求的数字，第二个数是第一个数的平方，且第二个数是回文数。
提示:
USACO Training
限制:
每个测试点1秒
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

样例 2 :
输入:
18
输出:
1 1
2 4
3 9
4 G
11 121
22 484
2D 777
3B D0D
说明:
11 121（18*1+1=19，19*19=361，361->121）
 */
string zhuanhuan1(int p10, int B) // p10为十进制数，B为目标进制, 转换为逆序的字符串
{
    int r=1;
    string s;
    while(true) {
        if (r>p10) break;
        // 从个位数开始,逆序输出
        int sw=p10%(r*B)/r;
        char c;
        if (sw<=9) c='0'+sw;
        else c='A'+sw-10;
        s+=c;
        r*=B;
    }
    return s;
}

bool check(string s) // 判断是否是回文数
{
    int l=s.length();
    for (int i=0;i<l/2;i++) {
        if (s[i]!=s[l-i-1]) return false;
    }
    return true;
}


int main()
{
    /**
     *  遍历1到300
     *  对每个数求平方
     *  对该数平方做进制转换 -> 逆序字符串1
     *  判断逆序字符串1是否是回文数，不是跳过（和正序结论是一样的）
     *  如果是回文数， 对该数做进制转换 -> 逆序字符串2
     *  分别逆序输出两字符串1和字符串2（字符串1不用逆序，因为他是回文数）
     */


    int B;
    cin >> B;
    for (int i=1;i<=300;i++) {
        int p10=i*i;
        string s1=zhuanhuan1(p10,B);
        bool is_hw=check(s1);
        if (is_hw) {
            string s2=zhuanhuan1(i,B);
            // 逆序s1s2输出
            for (int j=s2.length()-1;j>=0;j--) printf("%c", s2[j]);
            printf(" ");
            for (int j=s1.length()-1;j>=0;j--) printf("%c", s1[j]);
            printf("\n");
        }
    }
    return 0;
}
