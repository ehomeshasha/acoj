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


int main()
{
    /**
     * 思路,
     * 合法的字符串，最里层一定有[],{},()其中一种
     *
     * 算法思路（删除法，不断删除子串直至全删完）
     * 遍历字符串，遇到白名单跳过
     * 标记[],{},()到白名单
     * 再重复遍历直到白名单不再增加
     * 那么则一定合法
     *
     *
     */
    char ch[105]={'\0'};
    gets(ch);
    int l=strlen(ch),li=0; // li上个字符坐标
    char lc,c; // lc上个字符，c当前字符
    while(true) {
        lc=ch[0],li=0;
        bool found=false;
        for (int i=1;i<l;i++) {
            c=ch[i];
            if (lc=='['&&c==']'||lc=='{'&&c=='}'||lc=='('&&c==')') { // 标记[],{},()到白名单
                // 重构数组
                int nch_idx=0;
                for (int j=0;j<l;j++) {
                    if (j==li||j==i) continue; // 跳过
                    ch[nch_idx++]=ch[j];
                }
                ch[nch_idx]='\0';ch[nch_idx+1]='\0';l-=2; // 删掉两个元素
                found=true;
                break;
            }
            lc=c;
            li=i;
        }
        if (!found) break; // 删到无可删除， 退出循环
    }
    if (ch[0]=='\0') printf("YES");
    else printf("NO");
    return 0;
}
