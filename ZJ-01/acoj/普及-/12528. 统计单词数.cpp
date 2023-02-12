#include <bits/stdc++.h>


using namespace std;

/**
一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。
现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章
中的某一独立单词在不区分大小写的情况下完全相同（参见样例1 ），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例2 ）。
输入格式:
共2行。
第1行为一个字符串，其中只含字母，表示给定单词；
第2行为一个字符串，其中只可能包含字母和空格，表示给定的文章。
输出格式:
一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，
 分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从0 开始）；
 如果单词在文章中没有出现，则直接输出一个整数−1。
限制:
1≤单词长度≤10。
1≤文章长度≤1,000,000。
样例 1 :
输入:
To
to be or not to be is a question
输出:
2 0
样例 2 :
输入:
to
Did the Ottoman Empire lose its power at that time
输出:
-1
 */

bool mycompare(char* w, int w_len, char* w2, int w2_len)
{
    if (w_len!=w2_len) return false; // 长度不同不匹配
    for (int i=0;i<w_len;i++) {
        // 逐个比较每个字符,不区分大小写，有个匹配不上就短路
        if (w[i]!=w2[i]&&abs(w[i]-w2[i])!=32) {
            return false;
        }
    }
    return true;
}
void mycleanup(char* w, int w_len)
{
    for (int i=0;i<w_len;i++)
        w[i]='\0';
}

int mygetlen(char *w) {
    int n=0;
    for (int i=0;i<10;i++) {
        if (w[i]=='\0') break;
        n++;
    }
    return n;
}

int main()
{
    char w[10]={'\0'},c,w2[100]={'\0'};
    int w2_cnt=0,chuxian=-1,cnt=0,f_i=0;
    cin >> w;
    getchar(); // 取出\n
    int w_len = mygetlen(w);
    for (;;) {
        c=getchar();
        if (c==' ') {
            // do judge
            if (mycompare(w,w_len,w2,w2_cnt)) {
                if (chuxian==-1) chuxian=f_i; // 第一次出现的位置
                cnt++; // 出现次数+1
            } else if (chuxian==-1) {
                f_i+=w2_cnt+1;
            }
            // clean up
            mycleanup(w2,w2_cnt);
            w2_cnt=0;
        } else if (c>='a'&&c<='z'||c>='A'&&c<='Z') {
            // add c
            w2[w2_cnt++] = c;
            w2[w2_cnt]='\0';
        } else {
            break;
        }
    }
    if (chuxian==-1) cout << chuxian << endl;
    else cout << cnt << " " << chuxian << endl;

    return 0;
}
