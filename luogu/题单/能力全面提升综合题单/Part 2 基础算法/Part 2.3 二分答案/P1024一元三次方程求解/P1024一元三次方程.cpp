#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1024

思路， 由提示可知， 可以用二分答案， l=-100, r=100
按1的区间进行遍历， 分别求解二分搜索打印即可
 */
double a,b,c,d;
int cnt=0;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

void binary_answer(double l, double r)
{
    double fx1=f(l),fx2=f(r),mid;
    if (fx1==0) {
        printf("%.2lf ",l);
        cnt++;
    }
    if (fx1*fx2<0) {
        while(r-l>=0.001) //二分控制精度。
        {
            mid=(l+r)/2;  //middle
            if(f(mid)*f(r)<0) l=mid;
            else r=mid;
        }
        printf("%.2lf ",r);
        cnt++;
    }
}

int main()
{
    cin >> a >> b >> c >> d;
    for (int i=-100;i<100;i++) {
        if (cnt==3) break;
        binary_answer(i,i+1);
    }
    // 暴力解法
//    double x=-100.0;
//    while(true)
//    {
//        if (abs(f(x))<=0.001) printf("%.2lf ", x);
//        x+=0.01;
//        if (abs(x-100)<=0.001) break;
//    }
//    return 0;
}
