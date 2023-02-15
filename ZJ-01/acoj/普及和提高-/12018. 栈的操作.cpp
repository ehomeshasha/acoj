#include <bits/stdc++.h>


using namespace std;

/**
小哼正在学习栈，初始时有一个空的栈，有两种操作。I和O，I（insert）表示要往栈顶插入一个元素，O（out）表示删除栈顶元素。
①I val 往栈顶加入一个权值为 val 的元素。
②O 删除栈顶元素。
如果操作②的栈是空的，不执行删除操作。
输入格式:
第1行有一个整数n
接下来n行
I表示要插入一个数
O表示将栈顶元素删除
输出格式:
一行，输出栈当中最后留下的数（从栈底开始，到栈顶结束），以空格隔开
限制:
50% 1<=n<=10000
100% 1<=n<=100000
样例 1 :
输入:
9
I 4
I 5
I 3
O
O
I 9
I 9
O
O
输出:
4
 */
struct St {
    int head;
    int *arr;
}  st;
void mpush(int d)
{
    st.arr[st.head++]=d;
}
void mdel()
{
    if (st.head==0) return;
    st.head--;
}
void mprint()
{
    for (int i=0;i<st.head;i++) {
        printf("%d ",st.arr[i]);
    }
}
int main()
{
    // 用栈求解
    int arr[100005]={0},n,d1;
    char t;
    st={0,arr};
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> t;
        if (t=='I') {
            cin >> d1;
            mpush(d1);
        } else if (t=='O') {
            mdel();
        }
    }
    mprint();
    return 0;
}
