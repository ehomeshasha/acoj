#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/**
输入二个正整数x0,y0(2<=x0<100000,2<=y0<=1000000),求出满足下列条件的P,Q的个数
条件:  1.P,Q是正整数
2.要求P,Q以x0为最大公约数,以y0为最小公倍数.
试求:满足条件的所有可能的两个正整数的个数.
输入格式:
2个正整数 x0, y0
输出格式:
1个数，表示求出满足条件的P,Q的个数
样例 1 :
输入:
3 60
输出:
4
说明:
P,Q有4种
3,60
15,12
12,15
60,3
 */

bool is_huzhi(int n1, int n2) {
    if (n1==1||n2==1) return true;
    if (n1%n2==0||n2%n1==0) return false;
    int min_n=min(n1,n2);
    for (int i=2;i*i<=min_n;i++) {
        if (n1%i==0&&n2%i==0) return false;
    }
    return true;
}

int main()
{
    int x0,y0,c1,c2,cnt=0,i;
    cin >> x0 >> y0;
    if (x0==y0) {
        cout << 1 << endl;
        return 0;
    }

    for (i=x0;i<=y0;i+=x0) {
        if (y0%i!=0) continue;
        // 检验是否是最小公倍数和最大公约数
        c1=i/x0;
        c2=y0/i;
        // c1 c2需要互质
        if(is_huzhi(c1, c2)) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
