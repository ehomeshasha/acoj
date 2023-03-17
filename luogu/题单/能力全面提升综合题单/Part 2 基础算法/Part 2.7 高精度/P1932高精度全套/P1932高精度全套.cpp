#include <bits/stdc++.h>
using namespace std;

int a[10005],b[10005],c[20005];
/**
https://www.luogu.com.cn/problem/P1932
 */
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
//    int* a=(int*)malloc(maxl*sizeof(int));
//    int* b=(int*)malloc(maxl*sizeof(int));
//    int* c=(int*)malloc((maxl+1)*sizeof(int));
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

string madd(string &sa, string &sb)
{
    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
//    int *a=(int*)malloc(maxl*sizeof(int));
//    int* b=(int*)malloc(maxl*sizeof(int));
//    int* c=(int*)malloc((maxl+1)*sizeof(int));
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

string mmulti(const string &sa, const string &sb)
{
    if (sa=="0"||sb=="0") return "0";
    int la=sa.length(),lb=sb.length();
//    int* a=(int*)malloc(la*sizeof(int));
//    int* b=(int*)malloc(lb*sizeof(int));
//    int* c=(int*)malloc((la+lb)*sizeof(int));
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

struct Result {
    string shang,yushu;
};
Result mdivide(string sa, string sb)
{
    if (sa=="0") return Result{"0","0"};
    int la=sa.length(),lb=sb.length();
    if (lb>la) return Result{"0",sa};

    // 如果sb长度不足，需要sb后置加0补齐到和sa相同长度
    int diffl=la-lb;
    for (int i=0;i<diffl;i++) sb+="0";
    // 先比较sa，sb高精度大小
    // 如果sa<sb，不够减，那么sb需要去掉最后一个0,然后diffl--，再重新进行比较（不用补0直接比较）
    // 如果够减，对sa，sb用高精度减法，然后用结果作为sa继续减，一直减到不够减，统计减的次数，
    // 最终不够减继续去掉最后一个0，然后diff--，再重新进行比较
    // 当diff为0并且减到不够减，跳出循环，当时最后一个结果作为余数
    string shang,yushu;
    while (diffl>=0) {
        int cnt1=0;
        while(compare(sa,sb)) {
            string sc=msub(sa,sb);
            sa=sc;
            cnt1++;
        }
        shang+=to_string(cnt1);
        diffl--;
        if (diffl==-1) yushu=sa;
        else sb=sb.substr(0,sb.length()-1); // 去掉最后一个0
    }
    string shang2;
    int lc=0;
    while (shang[lc]=='0'&&lc<shang.length()-1) lc++;
    for (int i=lc;i<shang.length();i++) {
        shang2+=shang[i];
    }
    return Result{shang2,yushu};
}



int main()
{
    string sa,sb;
    cin >> sa >> sb;
    string sum1=madd(sa,sb);
    string sub1=msub(sa,sb);
    string multi1=mmulti(sa,sb);
    Result div1=mdivide(sa,sb);
    cout << sum1 << "\n";
    cout << sub1 << "\n";
    cout << multi1 << "\n";
    cout << div1.shang << "\n";
    cout << div1.yushu << "\n";
    return 0;
}
