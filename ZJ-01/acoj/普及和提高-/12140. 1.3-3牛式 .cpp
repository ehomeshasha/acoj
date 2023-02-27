#include <bits/stdc++.h>


using namespace std;

/**
下面是一个乘法竖式，如果用我们给定的那n个数字来替代*，可以使式子成立的话，我们就叫这个式子牛式。
    ***
x   **
----------
    ***
    ***
----------
   ****
数字只能取代*，当然第一位不能为0,况且给定的数字里不包括0。
注意一下在美国的学校中教的“部分乘积”，第一部分乘积是第二个数的个位和第一个数的积，第二部分乘积是第二个数的十位和第一个数的乘积.
写一个程序求出所有牛式的总数。
输入格式:

Line 1:数字的个数n。
Line 2:N个用空格分开的数字（每个数字都属于{1,2,3,4,5,6,7,8,9}）。
输出格式:

共一行，一个数字。表示牛式的总数。
提示:

注意：结果只能为4位
样例 1 :

输入:
5
2 3 4 6 8
输出:
1
说明:
          222
    x      22
   ----------
          444
         444
   ----------
         4884
 */
int path[5]={0};
int numbers[9]={0},N,idx=0,ans=0,tot=0;

void print_path()
{
    for (int i=0;i<5;i++) printf("%d",path[i]);
//    printf("\n");
    cout << endl;
}
bool is_find(int n)
{
    for (int i=0;i<N;i++) {
        if (n==numbers[i]) return true;
    }
    return false;
}

int mpow(int x)
{
    int res=1;
    for (int i=0;i<x;i++) {
        res*=10;
    }
    return res;
}

bool mcheck(int n, int len)
{
    if (n>mpow(len)) return false;
    // 分离各数位
    for (int r=1;r<=n;r*=10) {
        int sw=n%(r*10)/r;
        if (!is_find(sw)) return false;
    }
    return true;
}

bool check_niushi()
{
    bool niushi=true;
    int n1=path[0]*100+path[1]*10+path[2];
    int n2=path[3]*10+path[4];
    int n3=n1*path[4];
    if (!mcheck(n3,3)) niushi=false;
    int n4=n1*path[3];
    if (niushi&&!mcheck(n4,3)) niushi=false;
    int n5=n1*n2;
    if (niushi&&!mcheck(n5,4)) niushi=false;
    return niushi;
}

void trace(int step)
{
    if (step==5) {
        if (check_niushi()) ans++;
//        print_path();
//        tot++;
        return;
    }
    for (int i=0;i<N;i++) {
        path[step]=numbers[i];
        trace(step+1);
        path[step]=0; // 回溯
    }

}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> numbers[idx++];
    }
    // 回溯算法求全排列
    trace(0);
    printf("%d\n",ans);
//    printf("%d\n",tot);
    return 0;
}
