#include <bits/stdc++.h>


using namespace std;

/**
R 国和 S国正陷入战火之中，双方都互派间谍，潜入对方内部，伺机行动。
历尽艰险后，潜伏于 S国的 R 国间谍小 C 终于摸清了 S国军用密码的编码规则：
1． S 国军方内部欲发送的原信息经过加密后在网络上发送，原信息的内容与加密后所 得的内容均由大写字母‘A’-‘Z’构成（无空格等其他字符） 。
2． S国对于每个字母规定了对应的“密字” 。加密的过程就是将原信息中的所有字母替 换为其对应的“密字” 。
3． 每个字母只对应一个唯一的“密字” ，不同的字母对应不同的“密字” 。 “密字”可以 和原字母相同。
例如，若规定‘A’的密字为‘A’ ， ‘B’的密字为‘C’ （其他字母及密字略） ，则原信 息“ABA”被加密为“ACA” 。

现在，小 C 通过内线掌握了 S 国网络上发送的一条加密信息及其对应的原信息。小 C 希望能通过这条信息，破译 S 国的军用密码。
 小 C 的破译过程是这样的：扫描原信息，对 于原信息中的字母 x（代表任一大写字母） ，找到其在加密信息中的对应大写字母 y，并认为 在密码里 y是 x 的密字。
 如此进行下去直到停止于如下的某个状态：
1． 所有信息扫描完毕， ‘A’-‘Z’ 所有 26 个字母在原信息中均出现过并获得了相应 的“密字” 。
2． 所有信息扫描完毕，但发现存在某个（或某些）字母在原信息中没有出现。
3． 扫描中发现掌握的信息里有明显的自相矛盾或错误（违反 S国密码的编码规则） 。
例如，某条信息“XYZ”被翻译为“ABA”就违反了“不同字母对应不同密字”的规则。
在小 C 忙得头昏脑涨之际，R 国司令部又发来电报，要求他翻译另外一条从 S 国刚刚 截取到的加密信息。
 现在请你帮助小 C：通过内线掌握的信息，尝试破译密码。然后利用破 译的密码，翻译电报中的加密信息。
输入格式:
输入共3行，每行为一个长度在 1 到100 之间的字符串。
第 1 行为小C 掌握的一条加密信息。
第 2 行为第1 行的加密信息所对应的原信息。
第 3 行为R国司令部要求小 C 翻译的加密信息。
输入数据保证所有字符串仅由大写字母‘A’-‘Z’构成，且第 1 行长度与第 2 行相等。
输出格式:

输出共1行。
若破译密码停止时出现 2，3 两种情况，请你输出“Failed” （不含引号，注意首字母大
写，其它小写） 。
否则请输出利用密码翻译电报中加密信息后得到的原信息。
提示:

NOIP提高组2009
限制:

每个测试点1s
样例 1 :

输入:
AA
AB
EOWIE
输出:
Failed
说明:
原信息中的字母‘A’和‘B’对应相同的密字，输出“Failed”。
样例 2 :

输入:
QWERTYUIOPLKJHGFDSAZXCVBN
ABCDEFGHIJKLMNOPQRSTUVWXY
DSLIEWO
输出:
Failed
说明:
字母‘Z’在原信息中没有出现，输出“Failed”。
样例 3 :
输入:
MSRTZCJKPFLQYVAWBINXUEDGHOOILSMIJFRCOPPQCEUNYDUMPP
YIZSDWAHLNOVFUCERKJXQMGTBPPKOIYKANZWPLLVWMQJFGQYLL
FLSO
输出:
NOIP
 */

int main()
{
    // A-Z 'A'-90, 存储到一个数组, 下标为 'A'-'A', 值为字符
    char m[26]={'\0'},m_r[26]={'\0'},jm_c,ys_c,cs_c;
    int m_cnt=0;
    string jm, ys, cs, res;
    cin >> ys >> jm >> cs;
    if (jm.length()!=ys.length()) {
        cout << "Failed";   // 长度必须相同
        return 0;
    }
    for (int i=0;i<jm.length();i++) {
        jm_c=jm[i];ys_c=ys[i];
        // 判断字典里面有没有， 没有则写入， 有则判断是否相同， 不相同为密码规则矛盾
        if (m[ys_c-'A']=='\0') {
            m[ys_c-'A']=jm_c;
            m_cnt++;
        } else {
            if (m[ys_c-'A']!=jm_c) {
                cout << "Failed";
                return 0;
            }
        }
        // 必须一一对应
        if (m_r[jm_c-'A']=='\0') {
            m_r[jm_c-'A']=ys_c;
        } else {
            if (m_r[jm_c-'A']!=ys_c) {
                cout << "Failed";
                return 0;
            }
        }
        if (m_cnt==26) break;
    }
    if (m_cnt!=26) { // 没有集齐所有26个字母
        cout << "Failed";
        return 0;
    }
    // 尝试翻译
    for (int i=0;i<cs.length();i++) {
        printf("%c",m[cs[i]-'A']);
    }
    return 0;
}
