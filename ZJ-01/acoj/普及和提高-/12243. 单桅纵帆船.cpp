#include <bits/stdc++.h>


using namespace std;

/**
船体的结构是不能随意修改的，那样会破坏整艘船和谐的韵律..
虽然说.如果沿岸航行的话是不会预见太大的海浪的，但是还要小心保护桅杆和船帆..
毕竟对于小s这样的单桅帆船，桅杆和船帆如果受损的话。那一定是很危险的，.而这种危险.，通常是由于在颠簸中丧失了平衡造成的。
我们把目光聚焦在桅杆的结构，对于三角帆，可以把支撑它的三根横木之间连接的地方的耦合度记为a,b,c。
每根横木的耦合度计算方式不同，并且和长度和所使用的材料也没有必然联系。
《大航海家的旅行札记》一书告诉我们，如果可以刚好满足a+b > c且a - b
每一次可以如下估计。
a = b + c - a;（这个式子也适合其它两根横木，即每根横木经过颠簸后的估值可以通过当前两外横木耦合度和减去自己的值，即得到下一次该横木的耦合度）
而当a,b,c三个的数值无法构成一组三角形的时候，支撑船帆的桅杆将坍塌，我们想估计一下，这支船的桅杆最多可以承受住多少次剧烈摇晃。这个关系到.我们可以航行到多远。

输入格式:

每个测试点有多组数据。
每一行有三个数，表示三根横木之间连接的地方最初的耦合度a b c
输出格式:

有多行，每行有一个数表示这支船的桅杆最多可以承受住多少次剧烈摇晃。
如果这个答案超过了9999那么输出“The voyage seemed endless... ”（双引号中的内容，不含有双引号）。
这些船只可能一开始就是坏的，这个时候只需要输出一个-1。
样例 1 :

输入:
3 4 5
4 4 3
输出:
0
2
 */
#define int long long
bool valid(int &a, int &b, int &c)
{
    if (a+b<=c||a+c<=b||b+c<=a) return false;
    return true;
}
void dianbo(int &a, int &b, int &c)
{
    int A=a,B=b,C=c;
    a=B+C-A,b=A+C-B,c=A+B-C;
}

#undef int
int main()
{
#define int long long
    int A,B,C;
    while(scanf("%lld %lld %lld\n",&A,&B,&C)!=EOF) {
        if (!valid(A,B,C)) {
            printf("-1\n");
            continue;
        }
        bool finish=false;
        for (int i=1;i<=9999;i++) {
            dianbo(A,B,C);
            if (!valid(A,B,C)) {
                printf("%lld\n",i-1); // i次颠簸挂了，只能最大承受i-1次颠簸
                finish=true;
                break;
            }
        }
        if (finish) continue;
        printf("The voyage seemed endless... \n"); // 9999次颠簸都没挂，输出endless
    }
    return 0;
}
