#include <bits/stdc++.h>


using namespace std;

/**
下面是一个乘法竖式，如果用我们给定的那n个数字来取代*，可以使式子成立的话，我们就叫这个式子牛式。
    ***
x   **
----------
    ***
    ***
----------
   ****
数字只能取代*，当然第一位不能为0,况且给定的数字里不包括0。
注意一下在美国的学校中教的“部分乘积”，第一部分乘积是第二个数的个位和第一个数的积，第二部分乘积是第二个数的十位和第一个数的乘积.
写一个程序找出所有的牛式。
输入格式:
第一行：数字的个数n。
第二行：N个用空格分开的数字（每个数字都属于{1,2,3,4,5,6,7,8,9}）。
输出格式:
共一行，一个数字。表示牛式的总数。
提示:
USACO Training
限制:
每个测试点1秒
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
注意：结果只能为4位
 */

int mmax_bits(int n)
{
    int r=1,bits=0;
    while(r<=n) {
        r*=10;
        bits++;
    }
    return bits;
}

bool mvector_find(vector<int> &numbers, int n) {
    for (int i=0;i<numbers.size();i++) {
        if (numbers[i]==n) return true;
    }
    return false;
}

bool mcheck(int n,vector<int> &numbers, int l)
{
    int max_bits=mmax_bits(n);
    if (max_bits!=l) return false;
    int r=1;
    for (int i=0;i<max_bits;i++) {
        // 从个位开始分离
        int sw=n%(10*r)/r;
        if (!mvector_find(numbers,sw)) return false;
        r*=10;
    }
    return true;
}
int mpow(int radix,int n) {
    int r=1;
    for (int i=0;i<n;i++) r*=radix;
    return r;
}
void mchoose(vector<int> &result, vector<int> &numbers, int cengshu, int n, int add)
{
    if (cengshu==n+1) {
        result.push_back(add);
        return;
    }
    for (int i=0;i<numbers.size();i++) {
        int add1=add+mpow(10,n-cengshu)*numbers[i];
        mchoose(result, numbers, cengshu+1, n, add1);
    }
}

int main()
{
    // 暴力枚举所有可能性
    int n,t,cnt=0;
    vector<int> numbers,n1,n2,nn1,nn2;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> t;
        numbers.push_back(t);
    }
    // 挑选数字的游戏
    mchoose(n1,numbers,1,3,0);
    mchoose(n2,numbers,1,2,0);

//    for (int i=0;i<numbers.size();i++) {
//        for (int j=0;j<numbers.size();j++) {
//            for (int k=0;k<numbers.size();k++) {
//                n1.push_back(numbers[i]*100+numbers[j]*10+numbers[k]);
//            }
//        }
//    }
//    for (int i=0;i<numbers.size();i++) {
//        for (int j=0;j<numbers.size();j++) {
//            n2.push_back(numbers[i]*10+numbers[j]);
//        }
//    }

    for (int i=0;i<n1.size();i++) {
        for (int j=0;j<n2.size();j++) {
            // 判断是否牛式
            bool res=mcheck(n1[i]*(n2[j]%10),numbers,3); // 个位乘积
            if (!res) continue;
            res=mcheck(n1[i]*(n2[j]%100/10),numbers,3); // 十位乘积
            if (!res) continue;
            // 判断是否牛式
            res=mcheck(n1[i]*n2[j],numbers,4);
            if (!res) continue;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
