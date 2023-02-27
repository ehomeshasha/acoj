#include <bits/stdc++.h>


using namespace std;

/**
农夫约翰的奶牛不停地从他的农场中逃出来，导致了很多损害。为了防止它们再逃出来，他买了一只很大的号码锁以防止奶牛们打开牧场的门。
农夫约翰知道他的奶牛很聪明，所以他希望确保它们不会在简单地试了很多不同的号码组合之后就能轻易开锁。
锁上有三个转盘，每个上面有数字1..N (1 <= N <= 100)，因为转盘是圆的，所以1和N是相邻的。
有两种能开锁的号码组合，一种是农夫约翰设定的，还有一种“预设”号码组合是锁匠设定的。
但是，锁有一定的容错性，所以，在每个转盘上的数字都与一个合法的号码组合中相应的数字相距两个位置以内时，锁也会打开。
比如说，如果农夫约翰的号码组合是(1,2,3)，预设号码组合是(4,5,6)，在转盘被设定为(1,4,5)
（因为这和农夫约翰的号码组合足够接近）或(2,4,8)（因为这和预设号码组合足够接近）。
注意，(1,5,6)并不会打开锁，因为它与任一号码组合都不够接近。
给出农夫约翰的号码组合和预设号码组合，请计算能够开锁的不同的号码组合的数目。号码是有序的，所以(1,2,3)与(3,2,1)不同。
输入格式:
第一行：整数N。
第二行：三个以空格分隔的整数，为农夫约翰的号码组合。
第三行：三个以空格分隔的整数，为预设号码组合（可能与农夫约翰的号码组合相同）。
输出格式:
第一行：所有不同的能够开锁的号码组合的总数。
样例 1 :
输入:
50
1 2 3
5 6 7
输出:
249
说明:
每个转盘的标号是1..50。农夫约翰的号码组合是(1,2,3)，预设号码组合是(5,6,7)。

 */
int N,ans,p1[3],p2[3],path[3]={0},mode_list[3]={0}; // 1和N是相邻的, 别忘了mod, mode=1,1match, mode=2 2math, mode=3, all match

void mprint()
{
    for (int i=0;i<3;i++) printf("%d ",path[i]);
    printf("\n");
}

bool is_near(int n1, int n2) // 判断两个数字是否相邻, 1和N是相邻的
{
    if (abs(n1-n2)<=2) return true;
    if (n1>n2&&abs((n2+N)-n1)<=2) return true;
    if (n2>n1&&abs((n1+N)-n2)<=2) return true;
    return false;
}
void trace(int step)
{
    if (step==3) {
//        mprint();
        ans++;
        return;
    }
    for (int i=1;i<=N;i++) {
        bool match_p1=is_near(i,p1[step]);
        bool match_p2=is_near(i,p2[step]);
        // 剪枝: 如果数字相邻，那么就可以继续，否则直接continue
        if (!match_p1&&!match_p2) continue;
        int mode=0;
        if (step>0&&mode_list[step-1]==1) mode=1;
        else if (step>0&&mode_list[step-1]==2) mode=2;
        else if (match_p1&&!match_p2) mode=1;
        else if (match_p2&&!match_p1) mode=2;
        if (mode==1&&!match_p1) continue; // 破坏延续性就continue
        if (mode==2&&!match_p2) continue; // 破坏延续性就continue
        path[step]=i;
        mode_list[step]=mode;
        trace(step+1);
        path[step]=0;
        mode_list[step]=0;
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<3;i++) cin >> p1[i];
    for (int i=0;i<3;i++) cin >> p2[i];
    trace(0);
    cout << ans;
    return 0;
}
