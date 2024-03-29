#include <bits/stdc++.h>


using namespace std;

/**
你有一条由N个红色的，白色的，或蓝色的珠子组成的项链(3<=N<=350)，珠子是随意安排的。 这里是 n=29 的二个例子:



           1 2                                 1 2
         r b b r                            b r r b
        r          b                        b         b
       r            r                      b            r
      r              r                    w              r
     b                r                 w                w
    b                  b              r                    r
   b                    b            b                    b
  b                     b             r                   b
   r                    r               b                 r
    b                 r                  r              r
     b               r                    r            r
       r           r                        r        b
          r b r                              r r w
图片 A 图片 B
r 代表 红色的珠子
b 代表 蓝色的珠子
w 代表 白色的珠子
第一和第二个珠子在图片中已经被作记号。 图片 A 中的项链可以用下面的字符串表示：
brbrrrbbbrrrrrbrrbbrbbbbrrrrb
假如你要在一些点打破项链,展开成一条直线，然后从一端开始收集同颜色的珠子直到你遇到一个不同的颜色珠子，在另一端做同样的事(颜色可能与在这之前收集的不同)。 确定应该在哪里打破项链来收集到最大数目的珠子。
例如，在图片 A 中的项链中，在珠子 9 和珠子 10 或珠子 24 和珠子 25 之间打断项链可以收集到8个珠子。

白色珠子什么意思?
在一些项链中还包括白色的珠子(如图片B) 所示。
当收集珠子的时候，一个被遇到的白色珠子可以被当做红色也可以被当做蓝色。
表现含有白珠项链的字符串将会包括三个符号 r ， b 和 w 。
写一个程序来确定从一条被给出的项链可以收集到的珠子最大数目。

输入格式:

第 1 行: N, 珠子的数目
第 2 行: 一串长度为N的字符串, 每个字符是 r ， b 或 w。
输出格式:

单独的一行 最大可能取得的珠子数
提示:

USACO Training
限制:

每个测试点1秒
样例 1 :

输入:
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
输出:
11
 */
int main()
{
    /**
     * 难点在取模数
     * 和特判
     */


    int N,l,max_cnt=0;
    string s;
    cin >> N >> s;
    l=s.length();
    for (int i=0;i<l;i++) {
        // 尝试在i处断开
        // 往右看
        int cnt=0;
        char start_c=s[i],c;
        cnt++;
        for (int j=(i+1)%N;;j=(j+1)%N) {
            c=s[j];
            if (start_c!='w'&&c!='w'&&start_c!=c) break;
            // 增加一个珠子数目
            if (c!='w'&&start_c=='w') start_c=c; // 如果初始是白色珠子，则遇到的第一个非w的进行颜色确定
            cnt++;
            // 交叉break
            if (cnt==N) { // 数完了所有珠子，一定是最大的，直接结束程序
                printf("%d",N);
                return 0;
            }
        }

        start_c=s[(i-1+N)%N];
        cnt++;
        // 往左看
        for (int j=(i-2+N)%N;;j=(j-1+N)%N) {
            c=s[j];
            if (start_c!='w'&&c!='w'&&start_c!=c) break;
            // 增加一个珠子数目
            if (c!='w'&&start_c=='w') start_c=c; // 如果初始是白色珠子，则遇到的第一个非w的进行颜色确定
            cnt++;
            // 交叉break
            if (cnt==N) { // 数完了所有珠子，一定是最大的，直接结束程序
                printf("%d",N);
                return 0;
            }
        }
        if (max_cnt<cnt) {
            max_cnt=cnt;
        }
    }
    printf("%d", max_cnt);
    return 0;
}
