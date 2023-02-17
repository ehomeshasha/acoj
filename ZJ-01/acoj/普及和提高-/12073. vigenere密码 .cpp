#include <bits/stdc++.h>


using namespace std;

/**
16世纪法国外交家Blaise de Vigenère设计了一种多表密码加密算法——Vigenère密码。Vigenère密码的加密解密算法简单易用，且破译难度比较高，曾在美国南北战争中为南军所广泛使用。
在密码学中，我们称需要加密的信息为明文，用M表示；
 称加密后的信息为密文，用C表示；
 而密钥是一种参数，是将明文转换为密文或将密文转换为明文的算法中输入的数据，记为k。
 在Vigenère密码中，密钥k是一个字母串，k=k1k2…kn。当明文M=m1m2…mn时，得到的密文C=c1c2…cn，其中ci=mi@ki，
 @运算符的运算的规则如下表所示：
Vigenere加密在操作时需要注意：
运算忽略参与运算的字母的大小写，并保持字母在明文M中的大小写形式；
当明文M的长度大于密钥k的长度时，将密钥k重复使用。
输入格式:
输入共2行。
第一行为一个字符串，表示密钥k，长度不超过100，其中仅包含大小写字母。第二行为一个字符串，表示经加密后的密文，长度不超过1000，其中仅包含大小写字母。
输出格式:
输出共1行，一个字符串，表示输入密钥和密文所对应的明文。
提示:
ci=(mi-‘A‘+ki-‘A‘)mod26+‘A‘，
限制:
对于100%的数据，输入的密钥的长度不超过100，输入的密文的长度不超过1000，且都仅包含英文字母。
样例 1 :
输入:
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
输出:
Wherethereisawillthereisaway
 */
int get_dx(char c)
{
    if (c>='A'&&c<='Z') return 1; // 0为小写，1为大写
    return 0;
}

int main()
{
    // 思路， 求出mi%26的结果， 然后反推出mi
    // 注意大小写的坑, 保留明文的大小写形式，也就是说明文大小写只由密文决定，和密钥无关
    string k,c;
    cin >> k >> c;
    for (int i=0;i<c.length();i++) {
        char ki=k[i%k.length()]; // C
        char ci=c[i]; // Y
        // 求mi并打印 ci=(mi-‘A‘+ki-‘A‘)mod26+‘A‘，
        int dx=get_dx(ci);
        int dx2= get_dx(ki);
        char t1=dx==1?'A':'a';
        char t2=dx2==1?'A':'a';
        int ciA=ci-t1; // 0~25数字
        int kiA26=ki-t2; // 0~25数字
        int miA26=(ciA-kiA26+26)%26; // 0~25数字
        char mi=t1+miA26;
        printf("%c",mi);
    }

    return 0;
}
