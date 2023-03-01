#include <bits/stdc++.h>


using namespace std;

/**
排序是一种很频繁的计算任务。现在考虑最多只有三值的排序问题。一个实际的例子是，当我们给某项竞赛的优胜者按金银铜牌排序的时候。在这个任务中可能的值只有三种1，2和3。我们用交换的方法把他排成升序的。
写一个程序计算出，给定的一个1,2,3组成的数字序列，排成升序所需的最少交换次数。

输入格式:

第一行:
奖牌个数N (1 <= N <= 1000)
第 2行到第N+1行:
每行一个数字，表示奖牌。共N行。（1..3）
输出格式:

共一行，一个数字。表示排成升序所需的最少交换次数。
样例 1 :

输入:
9
2
2
1
3
3
3
2
3
1
输出:
4
 */
int N,a[1005],ans=0,i1,i2,c1,c2,c3;

//void search(int n1, int n2, int s_idx, int type)
//{
//    bool stop=true;
//    while(stop) {
//        stop=true;
//        for (int i=s_idx;i<N;i++) {
//            if (arr[i]==n1) {
//                s_idx=i+1;
//                continue;
//            }
//            if (arr[i]==n2) {
//                if (type==1) {
//                    for (int j=i+1;j<N;j++) {
//                        if (arr[j]==n1) {
//                            swap(arr[i],arr[j]);
//                            stop=false;
//                            ans++;
//                            break;
//                        }
//                    }
//                } else {
//                    for (int j=N-1;j>=i+1;j--) {
//                        if (arr[j]==n1) {
//                            swap(arr[i],arr[j]);
//                            stop=false;
//                            ans++;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//}
int main()
{
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> a[i];
    }
    // 划分区间的思路， 只移动区间外的，区间内不移动，是最少的交换次数
    for (int i=0;i<N;i++) {
        if (a[i]==1) c1++;
        else if (a[i]==2) c2++;
        else if (a[i]==3) c3++;
    }
    i1=c1+1,i2=c1+c2+1;
    // 先把在区间1内的不是1的交换走
    for (int i=0;i<c1;i++) {
        if (a[i]==2) { // 如果是2
            for (int j=c1;j<N;j++) {
                if (a[j]==1) {
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
            }
        } else if (a[i]==3) { // 如果是3， 尽量交换到3的区间内
            for (int j=N-1;j>=c1;j--) {
                if (a[j]==1) {
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    for (int i=c1;i<c1+c2;i++) { // 将2区间里面的3都换掉
        if (a[i]==3) {
            for (int j=N-1;j>=c1+c2;j--) {
                if (a[j]==2) {
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
