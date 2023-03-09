#include <bits/stdc++.h>


using namespace std;

/**
Dust的男朋友送了她一条珍珠项链，上面有m个珍珠。然而Dust是一个不懂美学的强迫症患者，她喜欢把项链上面的珍珠按照价值从小到大串起来。
现在Dust的男朋友又送了她n个珍珠，将项链考虑为一串链表，请你输出原项链的顺序以及增加珍珠过后的顺序。
输入格式:
共3行，第一行两个数m，n。
第二行m个数，表示项链的初始时每个珍珠的价值。
第三行n个数，表示新珍珠的价值。
输出格式:
一行m+n个数，表示排好的项链。
样例 1 :
输入:
10 2
2 6 4 8 8 8 5 3 9 3
3 10
输出:
10 9 8 8 8 6 5 4 3 3 3 2
 */
int a[200000];

bool msort(const int &a, const int &b)
{
    return a>b;
}
int main()
{
    int m,n;
    scanf("%d %d\n",&m,&n);
    for (int i=0;i<m;i++) scanf("%d ",&a[i]);
    scanf("\n");
    for (int i=0;i<n;i++) scanf("%d ",&a[i+m]);
    sort(a,a+m+n,msort);
    for (int i=0;i<m+n;i++) printf("%d ",a[i]);
    return 0;
}
