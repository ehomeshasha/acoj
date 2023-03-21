#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1303

方法1： 相乘单个数再相加
方法2： 直接模拟求解
 */
int a[2005],b[2005],c[4010];
int a1[4010],b1[4010],c1[4010],c2[4010];
string madd(string &sa, string &sb)
{
    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
    memset(a1,0,sizeof(a1));
    memset(b1,0,sizeof(b1));
    memset(c1,0,sizeof(c1));
    for (int i=0;i<la;i++) a1[la-i-1]=sa[i]-'0';
    for (int i=0;i<lb;i++) b1[lb-i-1]=sb[i]-'0';
    // 第一位个位，以此类推
    // 加法
    for (int i=0;i<maxl;i++) { // 对所有位数进行处理, 递推算法，从个位开始递推
        c1[i]+=a1[i]+b1[i];
        c1[i+1]=c1[i]/10;
        c1[i]=c1[i]%10;
    }
    // 因为是加法，所以只可能进一位
    string sc;
    int lc=maxl;
    while (c1[lc]==0&&lc>0) lc--;
    for (int i=lc;i>=0;i--) {
        sc+=c1[i]+'0';
    }
    return sc;
}

string mmultione(const int* a, const int b, const int la) // 单乘一个数
{
    memset(c2,0,sizeof(c2));
    for (int i=0;i<la;i++) {
        c2[i]+=a[i]*b;
        c2[i+1]=c2[i]/10;
        c2[i]=c2[i]%10;
    }
    string sc;
    for (int i=la;i>=0;i--) {
        if (i==la&&c2[i]==0) continue;
        sc+=c2[i]+'0';
    }
    return sc;
}

string mmulti1(const string &sa, const string &sb)
{
    if (sa=="0"||sb=="0") return "0";
    int la=sa.length(),lb=sb.length();
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
    for (int i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
    // a*b
    string sc="0";
    for (int i=0;i<lb;i++) {
        string mone=mmultione(a,b[i],la);
        for (int j=0;j<i;j++) mone+="0";
        sc=madd(sc,mone);
    }
    return sc;
}

string mmulti2(const string &sa, const string &sb)
{
    if (sa=="0"||sb=="0") return "0";
    int la=sa.length(),lb=sb.length();
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (int i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
    for (int i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
    // a*b
    for (int i=0;i<lb;i++) {
        for (int j=0;j<la;j++) {
            c[i+j]+=b[i]*a[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]=c[i+j]%10;
        }
    }
    string sc;
    int lc=la+lb-1;
    while (c[lc]==0&&lc>0) lc--;
    for (int i=lc;i>=0;i--) {
        sc+=c[i]+'0';
    }
    return sc;
}


int main()
{
//    freopen("/Users/shaluo/CLionProjects/acoj/luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.7 高精度/P1303高精度乘法/P1303_5.in","r",stdin);
//    freopen("/Users/shaluo/CLionProjects/acoj/luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.7 高精度/P1303高精度乘法/my5.out","w",stdout);
    string sa,sb,sc;
    cin >> sa >> sb;
//    sc=mmulti1(sa,sb);
    sc=mmulti2(sa,sb);
    cout << sc;
    return 0;
}
