#include <bits/stdc++.h>


using namespace std;

/**
小王同学在坐标系的（0，0）处，但是他找不到考试的试场，于是一边走路一边问路，每个被问路的人会告诉他一个指令（包括走路或转弯），
现在请编一个程序，显示他每次走路后的坐标（转弯后坐标不变，所以不必显示坐标）。
输入格式:
第一行一个数n,表示有n个指令,接下来n行每行一个指令，每个指令是“left” 或“right”或数字。
输出格式:
（有m个走路的指令）共m行,每一行一个坐标，表示走完后的坐标。如果只是原地转弯，从开始到最后从来不走动，则输出“(0,0)”.
提示:
第一题中,初始方向向y轴正半轴!!
限制:
对于50%的数据，0 < n <= 20;
对于100%的数据，0 < n <= 500。
所有数据都在longint范围内。
样例 1 :
输入:
6
2
left
2
right
right
3
输出:
(0,2)
(-2,2)
(1,2)
 */

int main()
{
#define int long long
    int N,x=0,y=0;
    int d=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    bool is_move=false;
    string s;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> s;
        if (s=="left") {
            d=(d+4-1)%4;
        } else if (s=="right") {
            d=(d+1)%4;
        } else {
            int moven=stoi(s);
            is_move=true;
            x+=dx[d]*moven,y+=dy[d]*moven;
            printf("(%lld,%lld)\n",x,y);
        }
    }
    if (!is_move) printf("(0,0)");
    return 0;
}
