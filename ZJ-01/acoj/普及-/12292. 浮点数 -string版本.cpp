#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
众所周知，12.456e1就是124.56的意思。
这个题目的任务就是把A.DeB的形式写成小数的形式。

输入格式:

输入包括一行，是一个形如A.DeB的字符串，其中A、D、B都是数字，范围限制见下。
输出格式:

输出包括一行，为A.DeB的小数形式。输出不能有前导零和小数部分的后缀0，如果答案恰为整数，小数点也不应输出。
限制:

输入的字符串长度不超过300，e后面表示位数的字符转化成数字后不超过100
样例 1 :

输入:
2.456e1
输出:
24.56
样例 2 :

输入:
2.456e3
输出:
2456
样例 3 :

输入:
2.456e5
输出:
245600
 */

int main()
{
    // 使用string来解
    string input, A, D, BS;
    cin >> input;
    int dot_i=input.find('.');
    A=input.substr(0,dot_i);
    int e_i=input.find('e');
    D=input.substr(dot_i+1,e_i-dot_i-1);
    BS=input.substr(e_i+1, input.length()-1-e_i);

    int B=stoi(BS);
    int la=A.length();
    int ld=D.length();
    if (B==0)
        if (ld==1&&D[0]=='0')
            printf("%s", A.c_str());
        else
            printf("%s.%s", A.c_str(), D.c_str());
    else if (B<0) {
        B=-B;
        if(B>=la) {
            string zadd;
            for(int i=0;i<B-la;i++)
                zadd+='0';
            printf("0.%s%s%s", zadd.c_str(), A.c_str(), D.c_str());
        } else {
            for (int i=la;i>=0;i--)
                if (i>la-B) A[i]=A[i-1];
            A[la-B]='.';
            A[la+1]='\0';
            printf("%s%s", A.c_str(), D.c_str());

        }
    } else {
        if (B>=ld) {
            string zadd;
            for(int i=0;i<B-ld;i++)
                zadd+='0';
            if(la==1&&A[0]=='0')
                printf("%s%s", D.c_str(), zadd.c_str());
            else
                printf("%s%s%s", A.c_str(), D.c_str(), zadd.c_str());
        } else {
            for (int i=ld;i>=0;i--)
                if (i>B) D[i]=D[i-1];
            D[B]='.';
            D[ld+1]='\0';
            printf("%s%s", A.c_str(), D.c_str());
        }
    }

    return 0;
}
