#include <bits/stdc++.h>


using namespace std;

/**
对于一群要互送礼物的朋友， 你要确定每个人收到的礼物比送出的多多少。
在这一个问题中， 每个人都准备了一些钱来送礼物， 而这些钱将会被平均分给那些将收到他的礼物的人。
然而， 在任何一群朋友中， 有些人将送出较多的礼物(可能是因为有较多的朋友)， 所以有些人就准备了较多的钱。
给出一群朋友， 没有谁的名字会长于 14 个字符， 给出每个人将花在送礼上的钱， 和将收到他的礼物的人的列表，
请确定每个人收到的比送出的钱多的数目。
输入格式:
输入格式
第 1 行：人数 N（ 2<= N<=10）
第 2 到 N+1 行： 这 N 个在组里人的名字， 一个名字一行
第 N＋2 到最后：这里的 N 段内容是这样组织的： 第一行是将会送出礼物人的名字。
 第二行包含二个数字 P 和 Q： 第一个数是 P 原有的钱的数目（ 在 0 到 2000 的范围里） ，
 第二个数 Q 是将收到这个送礼者礼物的人的个数， 如果Q不为0 , 将在下面 Q 行列出礼物的接受者的名字， 一个名字一行。
输出格式:
输出 N 行 每行是一个的名字加上空格再加上收到的比送出的钱多的数目。
 对于每一个人， 他名字的打印顺序应和他在输入的 2 到 N＋1 行中输入的顺序相同。
 所有的送礼的钱都是整数。 每个人把相同数目的钱给每位要送礼的朋友， 而且尽可能多给， 不能给出的钱被送礼者自己保留。
样例 1 :
输入:
5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0
输出:
dave 302
laura 66
owen -359
vick 141
amr -150
 */
struct User {
    int ru;
    int chu;
};
map<string,User> users;
int main()
{
    int N,money,renshu;
    string name,name1,name2,names[15];
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> name;
        users[name]=User{0,0};
        names[i]=name;
    }
    // 后续开始计算
    for (int i=1;i<=N;i++) {
        cin >> name1 >> money >> renshu;
        if (renshu==0) continue;
        int mny=money/renshu;
        users[name1].chu-=mny*renshu;
        for (int j=0;j<renshu;j++) {
            cin >> name2;
            users[name2].ru+=mny;
        }
    }
    map<string,User>::iterator iter;
    for (int i=1;i<=N;i++) {
        cout << names[i] << " " << users[names[i]].ru+users[names[i]].chu << "\n";
    }
    return 0;
}
