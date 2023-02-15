#include <bits/stdc++.h>


using namespace std;

/**
依次表示 一个Windows窗 用4个数定义位置:左边坐标、右边坐标、上边坐标、下边坐标。
现在,输入2个窗体的位置信息,判断它们的位置是否重叠。如果有请输出2个窗体的重叠面积,不重叠就输出 0。
输入格式:
两行,每行1个窗体的位置信息,int 范围以内。
输出格式:
输出2个窗体的重叠面积,不重叠就输出 0。
样例 1 :
输入:
10 100 20 60
60 160 50 200
输出:
400
 */
int a[4],b[4];
int cal_mj()
{
    int x=min(a[1],b[1])-max(a[0],b[0]);
    int y=min(a[3],b[3])-max(a[2],b[2]);
    if (x<0||y<0) return 0;
    return x*y;
}

int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> b[0] >> b[1] >> b[2] >> b[3];
    cout << cal_mj();

    return 0;
}
