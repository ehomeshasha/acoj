#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P2142
 */
int a[10100],b[10100],c[10100];

string msubb(const int* a, const int* b, int* c, int maxl, bool nagetive)
{
    for (int i=0;i<maxl;i++) { // 对所有位数进行处理, 递推算法，从个位开始递推
        c[i]+=a[i]-b[i]+10;
        c[i+1]=c[i]/10-1;
        c[i]=c[i]%10;
    }
    // 因为是减法，位数可能少
    string sc;
    if (nagetive) sc+="-";
    int lc=maxl-1;
    while (c[lc]==0&&lc>0) lc--;
    for (int i=lc;i>=0;i--) {
        sc+=c[i]+'0';
    }
    return sc;
}
bool compare(const string &sa, const string &sb)
{
    // 更简单的写法
    int la=sa.length(),lb=sb.length();
    if (la!=lb) return la>lb;
    return sa>=sb;
}
string msub(string &sa, string &sb)
{
    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (int i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
    for (int i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
    string sc;
    if (compare(sa,sb)) {
        sc=msubb(a,b,c,maxl,false);
    } else {
        sc=msubb(b,a,c,maxl,true);
    }
    return sc;
}


int main()
{
    string sa,sb,sc;
    cin >> sa >> sb;
    sc=msub(sa,sb);
    cout << sc;
    return 0;
}
