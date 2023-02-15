#include <bits/stdc++.h>


using namespace std;

/**
在编程当中我们只会用到三种括号：圆括号()，方括号[]和花括号{}，编译器在编译的时候会检查括号是否正确匹配。
 例如{[()]}、{()[]{}}都是合法的匹配。但是([)]则是不合法的匹配。请编写一个程序来判断输入的括号序列是否合法。
输入格式:
只有一行，为( ) [ ] { }组成的序列，长度不超过100
输出格式:
只有一行，如果是合法匹配则输出YES，不合法则输出NO，请注意大小写
限制:
每个测试点1秒
样例 1 :
输入:
{([()]{})}
输出:
YES
 */
struct St {
    int head;
    char *ch;
} st;

void mpush(char c)
{
    st.ch[st.head++]=c;
}

int mpop()
{
    return st.ch[--st.head];
}

int main()
{
    /**
     * 栈解法
     *
     * 算法思路
     * 如果遇到{,[,)入栈，遇到},],)出栈
     * 判断出栈情形下当前字符和栈顶元素是否匹配，匹配则弹出
     * 不匹配break，一定不合法
     * 最后检查栈，如果为空则合法否则不合法
     *
     */
    char ch[105]={'\0'};
    gets(ch);
    int l=strlen(ch);
    st={0,new char[l]};
    for (int i=0;i<l;i++) {
        if (ch[i]=='{'||ch[i]=='['||ch[i]=='(') mpush(ch[i]);
        if (ch[i]=='}'||ch[i]==']'||ch[i]==')') {
            char c1=mpop();
            if (c1!='{'&&ch[i]=='}'||c1!='['&&ch[i]==']'||c1!='('&&ch[i]==')') {
                printf("NO");
                return 0;
            }
        }
    }
    if (st.head==0) printf("YES");
    else printf("NO");
    return 0;
}
