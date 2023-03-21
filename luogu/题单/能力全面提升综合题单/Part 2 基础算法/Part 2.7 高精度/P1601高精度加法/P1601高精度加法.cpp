#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1601
 */
int a[505],b[505],c[505];

string madd(string &sa, string &sb)
{
    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
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

int main()
{
    string sa,sb,sc;
    cin >> sa >> sb;
    sc=madd(sa,sb);
    cout << sc;
    return 0;
}
