#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1303

方法1： 相乘单个数再相加
方法2： 直接模拟求解
 */
string madd(string &sa, string &sb)
{
    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
    int* a=(int*)malloc(maxl*sizeof(int));
    int* b=(int*)malloc(maxl*sizeof(int));
    int* c=(int*)malloc((maxl+1)*sizeof(int));
    for (int i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
    for (int i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
    // 第一位个位，以此类推
    // 加法
    for (int i=0;i<maxl;i++) { // 对所有位数进行处理, 递推算法，从个位开始递推
        c[i]+=a[i]+b[i];
        c[i+1]=c[i]/10;
        c[i]=c[i]%10;
    }
    // 因为是加法，所以只可能进一位
    string sc;
    int lc=maxl;
    while (c[lc]==0&&lc>0) lc--;
    for (int i=lc;i>=0;i--) {
        sc+=c[i]+'0';
    }
    return sc;
}

string mmultione(const int* a, const int b, const int la) // 单乘一个数
{
    int* c=(int*)malloc((la+1)*sizeof(int));
    for (int i=0;i<la;i++) {
        c[i]+=a[i]*b;
        c[i+1]=c[i]/10;
        c[i]=c[i]%10;
    }
    string sc;
    for (int i=la;i>=0;i--) {
        if (i==la&&c[i]==0) continue;
        sc+=c[i]+'0';
    }
    return sc;
}

string mmulti1(const string &sa, const string &sb)
{
    if (sa=="0"||sb=="0") return "0";
    int la=sa.length(),lb=sb.length();
    int* a=(int*)malloc(la*sizeof(int));
    int* b=(int*)malloc(lb*sizeof(int));
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
    int* a=(int*)malloc(la*sizeof(int));
    int* b=(int*)malloc(lb*sizeof(int));
    int* c=(int*)malloc((la+lb)*sizeof(int));
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
    string sa,sb,sc;
    cin >> sa >> sb;
//    sc=mmulti1(sa,sb);
    sc=mmulti2(sa,sb);
    cout << sc;
    return 0;
}
