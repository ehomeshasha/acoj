#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1932
 */
const int MAXN=20;
int a[MAXN],b[MAXN],c[MAXN];
char ca[MAXN],cb[MAXN];



int main()
{
    scanf("%s\n",ca);
    scanf("%s",cb);
    // 字符数组转整数数组
    int la=strlen(ca),lb=strlen(cb),maxl=max(la,lb);
    for (int i=0;i<la;i++) a[la-i-1]=ca[i]-'0';
    for (int i=0;i<lb;i++) b[lb-i-1]=cb[i]-'0';
    // 第一位个位，以此类推
    // 加法

    for (int i=0;i<maxl;i++) { // 对所有位数进行处理, 递推算法，从个位开始递推
        c[i]+=a[i]+b[i];
        c[i+1]=c[i]/10;
        c[i]=c[i]%10;
    }
    // 因为是加法，所以只可能进一位
    for (int i=maxl+1;i>=0;i--) {
        if (i==maxl+1&&c[i]==0) continue;
        printf("%d",c[i]);
    }

    return 0;
}
