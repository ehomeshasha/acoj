#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
在日常生活中，通过年、月、日这三个要素可以表示出一个唯一确定的日期。
牛牛习惯用8位数字表示一个日期，其中，前4位代表年份，接下来2位代表月 份，最后2位代表日期。显然：一个日期只有一种表示方法，而两个不同的日期的表 示方法不会相同。
牛牛认为，一个日期是回文的，当且仅当表示这个日期的8位数字是回文的。现 在，牛牛想知道：在他指定的两个日期之间包含这两个日期本身），有多少个真实存 在的日期是回文的。
一个8位数字是回文的，当且仅当对于所有的i （ 1 <=i<= 8 )从左向右数的第i个 数字和第9-i个数字（即从右向左数的第i个数字）是相同的。
例如：
•对于2016年11月19日，用8位数字20161119表示，它不是回文的。
•对于2010年1月2日，用8位数字20100102表示，它是回文的。
•对于2010年10月2日，用8位数字20101002表示，它不是回文的。
每一年中都有12个月份：
其中，1、3、5、7、8、10、12月每个月有31天；4、6、9、11月每个月有30天；而对于2月，闰年时有29天，平年时有28天。
一个年份是闰年当且仅当它满足下列两种情况其中的一种：
1.这个年份是4的整数倍，但不是100的整数倍；
2.这个年份是400的整数倍。
例如：
•以下几个年份都是闰年：2000、2012、2016。
•以下几个年份是平年：1900、2011、2014。
输入格式:
输入包括两行，每行包括一个8位数字。
第一行表示牛牛指定的起始日期。
第二行表示牛牛指定的终止日期。
保证date_i和都是真实存在的日期，且年份部分一定为4位数字，且首位数字不为0。
保证date1 —定不晚于date2。
输出格式:
输出一行，包含一个整数，表示在date1和date2之间，有多少个日期是回文的。
提示:
对于60%的数据，满足date1 = date2。
样例 1 :
输入:
20110101
20111231
输出:
1
说明:
对于样例1，符合条件的日期是20111102。
样例 2 :
输入:
20000101
20101231
输出:
2
说明:
对于样例2，符合条件的日期是20011002和20100102。
 */

int cnt = 0;
void check_huiwen(int* d)
{
    // 分离数位
    int on = d[1]*10000+d[2]*100+d[3], rn = 0, remainder, n;
    n = on;
    // 翻转
    while(n!=0)
    {
        remainder = n%10;
        rn = rn*10 + remainder;
        n /= 10;
    }
    if (on==rn) {
//        cout << d << endl;
        cnt++;
    }
}

bool is_date_equal(int a[4], int b[4])
{
    return a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3];
}
//一个年份是闰年当且仅当它满足下列两种情况其中的一种：
//1.这个年份是4的整数倍，但不是100的整数倍；
//2.这个年份是400的整数倍。
bool is_runnian(int y)
{
    return y%4==0&&y%100!=0 || y%400==0;
}

//每一年中都有12个月份：
//其中，1、3、5、7、8、10、12月每个月有31天；4、6、9、11月每个月有30天；而对于2月，闰年时有29天，平年时有28天。
int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void inc_date(int d[4])
{
    if (d[2]==2 && is_runnian(d[1])) m[2]=29;
    // 判断是否是月份最后一天
    if(d[3]==m[d[2]]) {
        d[3]=1;
        if (d[2]==12) {
            d[2]=1;
            d[1]++;
        } else
            d[2]++;
    } else
        d[3]++;
}

int main()
{
    string sdate, edate;
    cin >> sdate >> edate;
    int sdate_arr[4] = {0}, edate_arr[4] = {0};
    sdate_arr[1] = (sdate[0]-'0')*1000+(sdate[1]-'0')*100+(sdate[2]-'0')*10+(sdate[3]-'0');
    sdate_arr[2] = (sdate[4]-'0')*10+(sdate[5]-'0');
    sdate_arr[3] = (sdate[6]-'0')*10+(sdate[7]-'0');

    edate_arr[1] = (edate[0]-'0')*1000+(edate[1]-'0')*100+(edate[2]-'0')*10+(edate[3]-'0');
    edate_arr[2] = (edate[4]-'0')*10+(edate[5]-'0');
    edate_arr[3] = (edate[6]-'0')*10+(edate[7]-'0');

    while (!is_date_equal(sdate_arr, edate_arr)) {
        check_huiwen(sdate_arr);
        // 日期自增
        inc_date(sdate_arr);
    }
    check_huiwen(sdate_arr);

    cout << cnt << endl;

    return 0;
}
