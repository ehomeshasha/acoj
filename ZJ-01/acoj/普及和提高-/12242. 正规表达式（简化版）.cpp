#include <bits/stdc++.h>


using namespace std;

/**
在程序设计中，正则表达式(Regular Expressions)是用来处理复杂的字符串匹配以及模式识别问题的利器。
正则表达式的一种常见用法是，给定一个正则表达式和一个字符串，然后询问给定的正则表达式能否匹配整个字符串，你需要处理的就是这种询问。
当然，编写一个优秀的正则表达式引擎是有难度的，在这道题目中，你需要编程处理一种经过高度简化的正则表达式。
以下是这种正则表达式简化版的定义。
简化版的正则表达式可能包含以下字符：
0~9的数字，A~Z以及a~z的大小写英文字母，下划线“_”，方括号“[”和“]”，花括号“{”和“}”，短横线“-”。

其中，方括号和花括号一定以成对的方式出现且不会存在任何嵌套；

短横线一定出现在方括号内，且短横线两边的字符或者同为数字，或者同为小写字母，或者同为大写字母，
且短横线前面的字符的ASCII码不大于后面的字符；

花括号内只会出现数字。下面将数字、英文字母和下划线统称为“普通字符”。

出现在括号外的普通字符即表示与字符串中同样的单个字符匹配，
例如正则表达式“dd”可匹配字符串“dd”，但不能匹配“Dd”（因为大小写敏感），
也不能匹配“dd_”（正则表达式中不存在与最后的“_”匹配的元素）。

成对的方括号以及之间的部分也匹配字符串中的单个字符，但可以匹配的单个字符是一个集合，这个集合包含方括号中间的普通字符。
例如正则表达式“[Dd]d_engi”既能匹配“Dd_engi”又能匹配“dd_engi”；
正则表达式“[AaB][aAb]”可匹配“Ab”“aA”“Ba”等，但不能匹配“AB”“bA”或“bB”；
正则表达式“13[56789]”可匹配“135”“136”“137”“138”“139”中的任何一个，且不能匹配其它字符串。

 成对的方括号间，除了普通字符外，也可能出现短横线“-”，表示与连续的一段字符匹配。
例如，“[A-Z]”可匹配任何单个大写字符构成的字符串，如“E”“N”“G”“I”等；“[0-9]”可匹配任何单个数字构成的字符串；
“[2-4A-Z]”可匹配2~4的数字或者大写字母，但不能匹配“1”“5”或者“a”；
正则表达式“13[5-9]”、“13[85-79]”、“13[956-8]”、“13[5-78-9]”、“13[56789]”“13[98765]”“13[567898765]”“13[5-56-67-78-89-9]”互相之间都是等价的，
都表示可匹配“135”“136”“137”“138”“139”中的任何一个，且不能匹配其它字符串。

成对的花括号内含一个整数，表示“前一元素的标准应重复匹配若干次”。例如，“D{2}”表示将字符D重复两次，匹配字符串“DD”；
正则表达式“D{1}”与“D”等价；“D{11}”与“DDDDDDDDDDD”等价；“[Dd]{2}”可匹配“dd”“dD”“Dd”“DD”四种字符串；
“dd_[eng]{3}i”可匹配“dd_engi”“dd_eeei”“dd_enni”“dd_eeni”“dd_gnei”等。

成对的花括号的前面或者是普通字符或者是成对的方括号，不可能是另一对花括号。

正则表达式“1[35][0-9]{8}”的意义是“第一位是1，第二位可以是3或5，后面有8个0~9的数字”，它可以用来匹配中国大陆的手机号码。

 输入格式:
第一行是一个简化版的正则表达式。
以下若干行，每行一个字符串，直到文件结束，是对于第一行给定的正则表达式能否将其匹配的询问。
不会出现空字符串。
输出格式:
对于第二行开始的每个字符串，根据能否进行匹配，
输出一行“Regular Expression is Fun!”或者“Boring String Matching...”，不包括引号，其中的标点是英文标点（半角）。
限制:
每个输入文件不超过11行，大小不超过8KB；第二行起，每行不超过256个字符。
样例 1 :
输入:
[Dd]{2}_[eE][n-n][g_v][ii-jj]
dd_engi
Dd_engi
DD_envj
dD_eegi
dd-engi
ddengi
DD_Enhi
输出:
Regular Expression is Fun!
Regular Expression is Fun!
Regular Expression is Fun!
Boring String Matching...
Boring String Matching...
Boring String Matching...
Boring String Matching...
 */
#define int long long
struct Str {
    int si,ei,si2,ei2,mode; // mode=1代表[],=2代表{}
    string s;
};
int vis[75];
bool found1(int i, vector<Str> v, bool start)
{
    for (int j=0;j<v.size();j++) {
        if (v[j].mode!=1) continue; // 只判断{}
        if (start&&v[j].si2==i) return true;
        if (!start&&v[j].ei2==i) return true;
    }
    return false;
}

void update_vis(string s) // [a-z]{5}
{
    int i1,i2;
    char sc,ec;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='[') i1=i;
        else if (s[i]==']') i2=i;
    }
    s=s.substr(i1+1,i2-i1-1);
    // 重置vis数组
    for (int i=0;i<75;i++) vis[i]=0;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='-') {
            sc=s[i-1],ec=s[i+1];
            for (int j=sc-'0';j<=ec-'0';j++) {
                vis[j]=1;
            }
        } else if (i!=0&&s[i-1]!='-'||i!=s.length()-1&&s[i+1]!='-') {
            vis[s[i]-'0']=1;
        }
    }
}

bool check(char c)
{
    if (vis[c-'0']==1) return true;
    return false;
}

bool msort(Str a, Str b)
{
    return a.si<b.si;
}

int chongfu(string s)
{
    int i1,i2;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='{') i1=i;
        else if (s[i]=='}') i2=i;
    }
    return stoll(s.substr(i1+1,i2-i1-1));
}
#undef int
int main()
{
#define int long long
    vector<Str> v1;
    string s,s1;
    cin >> s;
    int i1,i2,i3,i4,ii1,ii2;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='{') {
            if (s[i-1]==']') { // ]{5}
                ii2=i-1;
                for (int j=i-1;j>=0;j--) {
                    if (s[j]=='[') {
                        i1=j,ii1=j;
                        break;
                    }
                }
            } else { // z{5}
                i1=i-1,ii1=i-1,ii2=i-1;
            }
        } else if (s[i]=='}') {
            i2=i;
            v1.push_back(Str{i1,i2,ii1,ii2,1,s.substr(i1,i2-i1+1)});
        }
    }
    for (int i=0;i<s.length();i++) {
        if (s[i]=='['&&!found1(i,v1,1)) {
            i3=i;
        } else if (s[i]==']'&&!found1(i,v1,0)) {
            i4=i;
            v1.push_back(Str{i3,i4,0,0,2,s.substr(i3,i4-i3+1)});
        }
    }
    if (!v1.empty()) {
        sort(v1.begin(),v1.end(),msort);
        int j=0,i5=0,i6=0;
        for (int i=0;i<s.length();i++) {
            if (i<v1[j].si) i6=i;
            else if (i==v1[j].si) {
                if (i6>=i5&&i!=0) {
                    v1.push_back(Str{i5,i6,0,0,0,s.substr(i5,i6-i5+1)});
                }
                i+=v1[j].ei-v1[j].si;
                if (i!=s.length()-1) {
                    i5=i+1;
                }
                j++;
            }
        }
        sort(v1.begin(),v1.end(),msort);
        if (v1[v1.size()-1].ei<s.length()-1) {
            i5=v1[v1.size()-1].ei+1,i6=s.length()-1;
            v1.push_back(Str{i5,i6,0,0,0,s.substr(i5,i6-i5+1)});
        }
        vector<Str>::iterator iter;
        for (iter=v1.begin();iter!=v1.end();) {
            if (iter->s.find("{0}")!=-1) v1.erase(iter);
            else iter++;
        }
    }

    string ans1="Regular Expression is Fun!",ans2="Boring String Matching...";
    while(cin >> s1) {
        // 思路
        // 先取得{}，然后将其前置元素合并，组成部分
        // 没有{}后，剩余的普通字符串做全匹配
        // 剩余的[]和[-]做字符匹配，注意[-]要去重
        if (v1.empty()) {
            if (s1==s) cout << ans1;
            else cout << ans2;
            continue;
        }
        bool is_match=true;
        int k=0,i;
        for (i=0;i<s1.length();i++) {
            int mode=v1[k].mode,si=v1[k].si,ei=v1[k].ei,si2=v1[k].si2,ei2=v1[k].ei2;
            string ss1=v1[k].s;
            if (mode==0) {
                for (int end=i+ei-si;i<=end;i++) {
                    if (s1[i]!=ss1[ei-si-end+i]) { // 必须完全匹配
                        is_match=false;
                        break;
                    }
                }
            } else if (mode==1) {
                int n1=chongfu(ss1);
                if (si2==ei2) { // s{5} 场景
                    // 解析出重复次数
                    for (int end=i+n1;i<end;i++) {
                        if (s1[i]!=ss1[0]) {
                            is_match=false;
                            break;
                        }
                    }
                } else { // [a-z]{5} 场景
                    update_vis(ss1);
                    for (int end=i+n1;i<end;i++) {
                        // 判断s1[i]是不是在方框范围内
                        if (!check(s1[i])) {
                            is_match=false;
                            break;
                        }
                    }
                }
            } else if (mode==2) {
                update_vis(ss1);
                if (!check(s1[i])) {
                    is_match=false;
                }
                i++;
            }
            i--;
            k++;
            if(!is_match) break;
        }
        if (k!=v1.size()) is_match=false; //如果所有校验规则都通过了，才可以通过
        if (i!=s1.length()) is_match=false; // 如果校验规则都通过，但是字符串没有结尾，说明没有匹配整个字符串
        if (is_match) cout << ans1;
        else cout << ans2;
        printf("\n");
    }
    return 0;
}
