#include <bits/stdc++.h>


using namespace std;

/**
有N个人要参加国际象棋比赛，该比赛要进行K场对弈。
每个人最多参加两场对弈，最少参加零场对弈。
每个人都有一个与其他人不相同的等级(用一个正整数来表示)。
在对弈中，等级高的人必须用黑色的棋子，等级低的人必须用白色的棋子。
每人最多只能用一次黑色的棋子和一次白色的棋子。
为了增加比赛的可观度，观众希望K场对弈中双方的等级差的总和最小。
比如有7个选手，他们的等级分别是30，17，26，41，19，38，18，要进行3场比赛。
最好的安排是 Player 2  vs  Player 7,  Player 7  vs  Player 5, Player 6  vs  Player 4，此时等级差的总和等于(18-17)+(19-18)+(41-38)=5，达到最小。
输入格式:
第一行两个正整数N, K;
接下来有N行，每行一个正整数，表示每个人的等级。
输出格式:
在第一行输出最小的等级差的总和。
限制:
对于90%的数据，1<=N<=3000; 时间复杂度可以在O(n^2)
对于100%的数据，1<=N<=100000; 时间复杂度要在O(n)或Olog(n)
保证所有输入数据中等级的值小于10^8，1<=K<=N-1。 1亿大小， 需要使用基数排序， 比较稀疏
样例 1 :
输入:
7 3
30
17
26
41
19
38
18
输出:
5
 */
void mysort(int* a, int a_len) {
    // 最大位数8
    int max_bits=8,r=1,c[10]={0},*tmp=new int[a_len];
    for (int i=0;i<max_bits;i++) {
        // 初始化c
        for (int j=0;j<10;j++)
            c[j]=0;
        // 从个位开始遍历, 铺进去
        for (int j=0;j<a_len;j++) {
            int sw=a[j]%(r*10)/r;
            c[sw]++;
        }
        // 累计
        for (int j=1;j<10;j++)
            c[j]+=c[j-1];
        // 临时填充
        for (int j=a_len-1;j>=0;j--) {
            int sw=a[j]%(r*10)/r;
            tmp[c[sw]-1]=a[j];
            c[sw]--;
        }
        // 回填数组
        for (int j=0;j<a_len;j++)
            a[j]=tmp[j];
        r*=10;
    }
    delete[] tmp;
}

int main()
{
    int N,K,a[100005]={0},a2[100005]={0},sum=0;
    cin >> N >> K;
    for (int i=0;i<N;i++)
        scanf("%d\n", &a[i]);
    mysort(a,N);
//    sort(a,a+N);
    for (int i=0;i<N-1;i++)
        a2[i]=a[i+1]-a[i];
    mysort(a2,N-1);
//    sort(a2,a2+N-1);
    for (int i=0;i<N-1;i++) {
        sum+=a2[i];
        if (i+1==K) break;
    }
    cout << sum;
    return 0;
}
