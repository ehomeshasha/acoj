#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P4552
 */
#define int long long
int N,p,q,now,before;
#undef int
int main()
{
#define int long long
    // 先转化差分数组diff
    // 要数列都相同， diff最终需要转换成
    // {d1,0,0,0,0,...,0}
    // diff数组是通过区间修改，因此可以任选两个值进行+1,-1操作
    // 要转换成目标diff数组， 可以任选两个+1,-1抵消是最优解
    // 假设p为所有需要+1的和，q为所有需要-1的和
    // 当执行完min(p,q)次操作后
    // 数组必定为 {d1, 2, 3, 0 , 0, 4}
    // 即剩余一些与d1同号的数字
    // 接下来就是将这些数字变成d1， 1种解法（通过修改di和dn+1 p-q次）
    // 或者修改d1， 解法有|p-q|种
    // （需要修改di 1次或者p-q次,以及修改di和dn+1 p-q-1~0次）
    // 所有答案数量为 |p-q|+1
    scanf("%lld",&N);
    scanf("%lld",&before); // 第一个元素作为before
    for (int i=2;i<=N;i++) {
        scanf("%lld",&now);
        int c=now-before;
        if (c>0) p+=c;
        else q-=c;
        before=now;
    }
    printf("%lld\n",min(p,q)+abs(p-q));
    printf("%lld",abs(p-q)+1);
    return 0;
}
