#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>

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
int mi(int n) {
    int res=1;
    for (int i=0;i<n;i++)
        res*=10;
    return res;
}

int main()
{
    char input[305], A[305], D[305], BS[3];
    scanf("%s", input);
    // 分离
    int find_dot=0;
    int find_e=0;
    for (int i=0;i<305;i++) {
        if(input[i]=='\0') {
            BS[i-find_e-1]='\0';
            break;
        }
        if(input[i]=='.') {
            A[i]='\0';
            find_dot=i;
            continue;
        }
        if(input[i]=='e') {
            D[i-find_dot-1]='\0';
            find_e=i;
            continue;
        }
        if(find_dot==0)
            A[i]=input[i];
        else {
            if (find_e==0)
                D[i-find_dot-1]=input[i];
            else
                BS[i-find_e-1]=input[i];
        }
    }

    int B=stoi(BS);
    int la=strlen(A);
    int ld=strlen(D);
    if (B==0)
        if (ld==1&&D[0]=='0')
            printf("%s", A);
        else
            printf("%s.%s", A, D);
    else if (B<0) {
        B=-B;
        if(B>=la) {
            char zadd[101];
            for(int i=0;i<B-la;i++)
                zadd[i]='0';
            zadd[B-la]='\0';
            printf("0.%s%s%s", zadd, A, D);
        } else {
            for (int i=la;i>=0;i--)
                if (i>la-B) A[i]=A[i-1];
            A[la-B]='.';
            A[la+1]='\0';
            printf("%s%s", A, D);

        }
    } else {
        if (B>=ld) {
            char zadd[101];
            for(int i=0;i<B-ld;i++)
                zadd[i]='0';
            zadd[B-ld]='\0';
            if(la==1&&A[0]=='0')
                printf("%s%s", D, zadd);
            else
                printf("%s%s%s", A, D, zadd);
        } else {
            for (int i=ld;i>=0;i--)
                if (i>B) D[i]=D[i-1];
            D[B]='.';
            D[ld+1]='\0';
            printf("%s%s", A, D);
        }
    }

    return 0;
}
