#include <bits/stdc++.h>


using namespace std;

/**
啊哈沃德有一个牛舍，他相信快乐的奶牛能产更多的奶，于是在他的谷仓里安装了一个巨大的迪斯科球，并计划教他的奶牛跳舞！
 啊哈沃德有N头牛(1≤N≤100)，N头牛最初会按某种顺序排成一排，为初始顺序。啊哈沃德查询了最流行的舞蹈排行榜，他决定让它门跳“牛舞”。
“牛舞”需要每头牛按特定的规律更换三次位置。为了让他的奶牛更容易找到自己的位置，
 啊哈沃德用位置1…N为他的奶牛标记位置，因此队列中的第一只奶牛将位于位置1，下一只位于位置2，以此类推，直到位置N。
奶牛更换位置的规律用N个数字描述，a1,a2,…,aN，在交换的过程中，位置i的牛会移动到位置ai(因此，每个ai的范围是1…N)。
 并且在交换过程中，每头牛都会移动到新的位置。幸运的是，所有的ai都是不同的，所以不会有两头奶牛试图移动到相同的位置。
啊哈沃德给每头牛都分配了不同的7位整数ID号。现在告诉你，N头奶牛交换了三次位置后的顺序，求它们的初始顺序。
输入格式:
一共三行数据，第一行输入包含N，表示奶牛的数量。第二行包含N个整数a1…aN，表示奶牛交换的规律。第三行，包含三次交换后N头奶牛的顺序，每头奶牛由其ID号指定。
输出格式:
N行输出，每行使用一个奶牛ID，N行表示奶牛在三次交换前的初始顺序。
限制:
1<=N<=100
样例 1 :
输入:
5
1 3 4 5 2
1234567 2222222 3333333 4444444 5555555
输出:
1234567
5555555
2222222
3333333
4444444
 */

int main()
{
    int a1[105],tmp[105],N,m[105],t;
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> t;
        m[t]=i;
    }
    for (int i=1;i<=N;i++) {
        cin >> t;
        a1[i]=t;
    }
    // 按照反序m跳3次即可
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=N;j++) {
            tmp[m[j]]=a1[j];
        }
        // 回填数组
        for (int j=1;j<=N;j++) a1[j]=tmp[j];
    }
    for (int i=1;i<=N;i++) printf("%d\n",a1[i]);
    return 0;
}
