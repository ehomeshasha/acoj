#include <bits/stdc++.h>


using namespace std;

/**
acoj有问题，只能提交到洛谷 https://www.luogu.com.cn/record/103166953


在威斯康辛州牛守志大农场经营者之中，都习惯于请会计部门用连续数字给母牛打上烙印。
但是,母牛本身并没感到这个系统的便利,它们更喜欢用它们喜欢的名字来呼叫它们的同伴，而不是用像这样的话"跟上吧，4364号"。
请写一个程序来帮助可怜的牧牛工将一只母牛的烙印编号翻译成一个可能的名字。
因为母牛们现在都有手机了，使用标准的按键的排布来把将数目翻译为文字( 除了 "Q" 和 "Z"):
2: A,B,C    5: J,K,L      8: T,U,V
3: D,E,F    6: M,N,O    9: W,X,Y
4: G,H,I     7: P,R,S
 3*3*3*3=81种
 3^12次方可能性 81*81*81=近50万可能性
可接受的名字都被放在这样一个叫作"dict.in" 的文件中，它包含一连串的少于 5,000个（准确地说是4617个）可被接受的牛的名字。
 (所有的名字都是大写的且已按字典序排列) 请读入母牛的编号并返回那些能从编号翻译出来并且在字典中的名字。
举例来说,编号 4734 能产生的下列各项名字:
GPDG GPDH GPDI GPEG GPEH GPEI GPFG GPFH GPFI GRDG GRDH GRDI GREG GREH GREI GRFG GRFH GRFI GSDG GSDH GSDI GSEG GSEH GSEI GSFG GSFH GSFI HPDG HPDH HPDI HPEG HPEH HPEI HPFG HPFH HPFI HRDG HRDH HRDI HREG HREH HREI HRFG HRFH HRFI HSDG HSDH HSDI HSEG HSEH HSEI HSFG HSFH HSFI IPDG IPDH IPDI IPEG IPEH IPEI IPFG IPFH IPFI IRDG IRDH IRDI IREG IREH IREI IRFG IRFH IRFI ISDG ISDH ISDI ISEG ISEH ISEI ISFG ISFH ISFI
碰巧，81个中只有一个"GREG"是有效的(在字典中)。
写一个程序来对给出的编号打印出所有的有效名字，如果没有则输出NONE。编号可能有12位数字。

输入格式:

单独的一行包含一个编号(长度可能从1到12)。
别忘了"dict.in"。
输出格式:

以字典顺序输出一个有效名字的不重复列表，一行一个名字。 如果没有有效名字，输出'NONE'。
提示:

数字只有8^n种排列（1与0不能用）
样例 1 :

输入:
4734
输出:
GREG
 */

int main()
{
    bool is_find= false;
    int N, yinshe[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
    char word[50]={'\0'},input[50];
    scanf("%s",input);
    N=strlen(input);
    for (int j=0;j<4617;j++) {
        scanf("%s\n",word);
        // word是字典里面的每行单词
        bool is_find1=true; // 当前是否找到
        if (strlen(word)!=N) {
            continue;
        }
        for (int i=0;i<N;i++) {
            if (input[i]-'0'!=yinshe[word[i]-'A']) {
                is_find1= false;
                break;
            }
        }
        if (!is_find1) continue;

        is_find=true; // 字典中有符合要求的
        printf("%s\n",word); // 字典序打印符合要求的
    }
    if (!is_find) printf("NONE");
    return 0;
}
