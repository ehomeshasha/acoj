#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
12394. 龙虎斗
https://www.acoj.com/problems/12394
输入
6
2 3 2 3 2 3
4 6 5 2
输出
2
 */
int main()
{
    long long n,a[100005],m,p1,s1,s2;
    long long p2,tmpp2, cha=0,min_cha,right_p2;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    cin >> m >> p1 >> s1 >> s2;
    for (int i=1;i<=n;i++)
        cha+=a[i]*(m-i);
    cha+=s1*(m-p1);
    min_cha=abs(cha);
    p2=cha/s2+m;
    right_p2=p2;
    // 从当前以及相邻元素寻找最优解
    for (int i=-1;i<=1;i++) {
        tmpp2=p2+i;
        long long tmp_cha=abs((tmpp2-m)*s2-cha);
        if (tmp_cha<min_cha) {
            min_cha=tmp_cha;
            right_p2=tmpp2;
        }
    }
    cout << right_p2 << endl;

    return 0;
}
