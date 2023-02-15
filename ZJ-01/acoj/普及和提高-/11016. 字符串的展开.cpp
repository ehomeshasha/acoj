#include <bits/stdc++.h>


using namespace std;

/**
在初赛普及组的“阅读程序写结果”的问题中，我们曾给出一个字符串展开的例子：如果在输入的字符串中，含有类似于“d-h”或者“4-8”的字串，我们就把它当作一种简写，
输出时，用连续递增的字母获数字串替代其中的减号，即，将上面两个子串分别输出为“defgh”和“45678”。
在本题中，我们通过增加一些参数的设置，使字符串的展开更为灵活。具体约定如下：
遇到下面的情况需要做字符串的展开：
 在输入的字符串中，出现了减号“-”，
 减号两侧同为小写字母或同为数字，
 且按照ASCII码的顺序，减号右边的字符严格大于左边的字符。
参数p1：
 展开方式。
 p1=1时，对于字母子串，填充小写字母；
 p1=2时，对于字母子串，填充大写字母。
 这两种情况下数字子串的填充方式相同。
 p1=3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充。
参数p2：
 填充字符的重复个数。
 p2=k表示同一个字符要连续填充k个。
 例如，当p2=3时，子串“d-h”应扩展为“deeefffgggh”。
 减号两边的字符不变。
参数p3：
 是否改为逆序：
 p3=1表示维持原来顺序，
 p3=2表示采用逆序输出，注意这时候仍然不包括减号两端的字符。
 例如当p1=1、p2=2、p3=2时，子串“d-h”应扩展为“dggffeeh”。
如果减号右边的字符恰好是左边字符的后继，只删除中间的减号，
 例如：“d-e”应输出为“de ”，“3-4”应输出为“34”。
 如果减号右边的字符按照ASCII码的顺序小于或等于左边字符，输出 时，要保留中间的减号，例如：“d-d”应输出为“d-d”，“3-1”应输出为“3-1”。
输入格式:
包括两行：
第1行为用空格隔开的3个正整数，一次表示参数p1，p2，p3。
第2行为一行字符串，仅由数字、小写字母和减号“-”组成。行首和行末均无空格。
输出格式:
只有一行，为展开后的字符串。
提示:
NOIP提高组2007
限制:
每个测试点1秒
40%的数据满足：字符串长度不超过5
100%的数据满足：1<=p1<=3，1<=p2<=8，1<=p3<=2。字符串长度不超过100
样例 1 :
输入:
1 2 1
abcs-w1234-9s-4zz
输出:
abcsttuuvvw1234556677889s-4zz
样例 2 :
输入:
2 3 2
a-d-d
输出:
aCCCBBBd-d
 */

int main()
{
    int p1,p2,p3,len=0; // no_s,no_e前后都包, no代表不变化的字符串数组
    char t[2],ch[105]={'\0'},c,lc,rc,new_ch[5000]={'\0'};
    vector<char> mid; // 中间字符数组
    cin >> p1 >> p2 >> p3;
    gets(t);
    gets(ch);
    // 获取长度
    for (int i=0;i<105;i++) {
        if (ch[i]=='\0') {
            len=i;
            break;
        }
    }
    // 直接进行打印输出，遇到需要改变的就改变
    for (int i=0;i<len;i++) {
        c=ch[i];
        if (c=='-') {
            if (i==0||i==len-1) { // 如果-在首个字符或者最后一个字符，即不存在左字符和右字符，不做处理
                printf("-");
            } else {
                // 好日子到头了， 要发生变化
                lc=ch[i-1];rc=ch[i+1]; // 左字符、右字符
                // 比较lc和rc
                // 如果减号右边的字符恰好是左边字符的后继，只删除中间的减号
                if (rc-lc==1) continue;
                // 如果减号右边的字符按照ASCII码的顺序小于或等于左边字符，输出 时，要保留中间的减号
                if (rc<=lc) printf("-");
                if (rc>lc) {
                    // 需要复杂的判断 p1,p2,p3
                    // 参数p1：
                    // 展开方式。
                    // p1=1时，对于字母子串，填充小写字母；
                    // p1=2时，对于字母子串，填充大写字母。
                    // 这两种情况下数字子串的填充方式相同。
                    // p1=3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充。
                    //参数p2：
                    // 填充字符的重复个数。
                    // p2=k表示同一个字符要连续填充k个。
                    // 例如，当p2=3时，子串“d-h”应扩展为“deeefffgggh”。
                    // 减号两边的字符不变。
                    //参数p3：
                    // 是否改为逆序：
                    // p3=1表示维持原来顺序，
                    // p3=2表示采用逆序输出，注意这时候仍然不包括减号两端的字符。
                    // 例如当p1=1、p2=2、p3=2时，子串“d-h”应扩展为“dggffeeh”。
                    // 减号两侧同为小写字母或同为数字，
                    // 且按照ASCII码的顺序，减号右边的字符严格大于左边的字符。

                    // 判断出处理类型， 数字=1,小写=2,大写=3
                    int deal_type=0;
                    mid.clear(); // 中间字符数组
                    for (int j=lc-'0'+1;j<rc-'0';j++) {
                        mid.push_back(j+'0');
                    }
                    if (rc>='a'&&rc<='z'&&lc>='a'&&lc<='z') deal_type=1; // 和p1匹配
                    if (rc>='A'&&rc<='Z'&&lc>='A'&&lc<='Z') deal_type=2;
                    if (rc>='0'&&rc<='9'&&lc>='0'&&lc<='9') deal_type=3;
                    if (deal_type==0) { // 不满足展开要求，不处理
                        printf("-");
                        continue;
                    }

                    if (p1==3) { // 填充星号
                        for (int j=0;j<mid.size();j++) {
                            mid[j]='*';
                        }
                    } else if (deal_type!=3&&deal_type!=p1) { // 需要做字母大小写转换处理
                        int sub1=deal_type==1?-32:32; // deal_type=1为小写转大写，=2为大写转小写
                        for (int j=0;j<mid.size();j++) {
                            mid[j]+=sub1;
                        }
                    }
                    // p1 finish

                    // p3 & p2 start
                    if (p3==2) {
                        // 逆序打印
                        for (int j=mid.size()-1;j>=0;j--) {
                            for (int k=0;k<p2;k++) {
                                printf("%c", mid[j]);
                            }
                        }
                    } else {
                        // 正序打印
                        for (int j=0;j<mid.size();j++) {
                            for (int k=0;k<p2;k++) {
                                printf("%c", mid[j]);
                            }
                        }
                    }
                }
            }
        } else {
            printf("%c",c);
        }
    }
    return 0;
}
