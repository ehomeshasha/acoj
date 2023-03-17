#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1480

高精度/低精度 逐位求商法
高精度/高精度 减法模拟除法
 */
struct Result {
    string shang,yushu;
};

// 高精度/低精度 逐位试商法
#define int long long
Result mdivide1(string &sa, string &sb)
{
    // a高精度，b低精度
    int la=sa.length();
    int* a=(int*) malloc(la*sizeof(int));
    int* c=(int*) malloc(la*sizeof(int));
    int b=stoi(sb);
    for (int i=0;i<la;i++) a[i]=sa[i]-'0';
    // 逐位试商
    int yushu=0;
    for (int i=0;i<la;i++) {
        // i=0
        // 判断a[0]/b
        // 够除 c[i]=a[0]/b
        // 余数 yushu=a[0]%b
        // 不够除 c[i]=0;余数 yushu=a[0]%b;
        // i=1
        // 判断(yushu*10+a[1])/b
        c[i]=(yushu*10+a[i])/b;
        yushu=(yushu*10+a[i])%b;
    }
    string shang;
    int lc=0;
    while(c[lc]==0&&lc<la-1) lc++;
    for (int i=lc;i<la;i++) {
        shang+=c[i]+'0';
    }
    string ys=to_string(yushu);
    return Result{shang,ys};
}
#undef int


string msub(const string &sa, const string &sb, bool nagetive)
{
    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
    int* a=(int*)malloc(maxl*sizeof(int));
    int* b=(int*)malloc(maxl*sizeof(int));
    int* c=(int*)malloc((maxl+1)*sizeof(int));
    for (int i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
    for (int i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
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
//    int la=sa.length(),lb=sb.length(),maxl=max(la,lb);
//    int* a=(int*)malloc(maxl*sizeof(int));
//    int* b=(int*)malloc(maxl*sizeof(int));
//    for (int i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
//    for (int i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
//    if (la!=lb) return la>lb;
//    for (int i=maxl-1;i>=0;i--) { // 从高位开始比，如果a的高位比b的高位小，那么返回false，即a<b
//        if (a[i]<b[i]) return false;
//    }
//    return true; // a>=b
}


// 高精度/高精度 减法模拟除法
Result mdivide2(string sa, string sb)
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
            string sc=msub(sa,sb,false);
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
    Result res=mdivide2(sa,sb);
    cout << res.shang << endl;
//    cout << res.yushu << endl;
    return 0;
}
