#include <bits/stdc++.h>


using namespace std;

/**
啊哈沃德要介绍一下啊哈编程学院，但是由于他粗心把句子中的”ahaschool”全部都写成了”ahascholl”，
 现在需要把句子中所有的” ahascholl”都换回”ahaschool”。
输入格式:
输入的一行字符串s，字符串中包含小写字母、空格，字符串长度不超过10000。
输出格式:
输出一行，输出替换错误单词的字符串，如果找不到输出-1。
限制:
10≤|s|≤10000
样例 1 :
输入:
the inital password of all studentds is ahascholl
输出:
the inital password of all studentds is ahaschool
说明:
句子中在句尾出现了” ahascholl”，直接替换为”ahaschool”。
 */

int main()
{
    char s[10005],c,search[9]={'a','h','a','s','c','h','o','l','l'},
            replace[9]={'a','h','a','s','c','h','o','o','l'};
    int s_idx=0,match_cnt=0;
    // 长度相同，下标不变
    gets(s);
    for (int i=0;i<10005;i++) {
        c=s[i];
        if (c=='\0'||c=='\n') break;
        if (c==search[s_idx]) s_idx++;
        if (s_idx==9) { // 全匹配
            // 替换
            for (int j=0;j<9;j++) {
                s[i+j-8]=replace[j];
            }
            // 复位
            s_idx=0;
            match_cnt++;
        }
    }
    if (match_cnt==0) cout << -1;
    else {
        for (int i=0;i<10005;i++) {
            c=s[i];
            if (c=='\0'||c=='\n') break;
            printf("%c", c);
        }
    }


    return 0;
}
