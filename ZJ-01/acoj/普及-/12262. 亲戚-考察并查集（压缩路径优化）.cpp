#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/**
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
输入格式:
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1<=Mi，Mj<=N，表示Ai和Bi具有亲戚关系。
接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
输出格式:
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。
样例 1 :
输入:
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
输出:
Yes
Yes
No
 */
int point[5005];
int f(int n) {
    if(n==point[n]) return n;
    return f(point[n]);
}
;
void join(int a, int b) {
    if(f(a)==f(b)) return;
    point[f(a)]=f(b);
}

int main()
{
    int n,m,p,mi,mj,pi,pj;
    cin >> n >> m >> p;
    // 并查集解法，集合算法
    for (int i=1;i<=n;i++)
        point[i]=i;
    for (int i=1;i<=m;i++) {
        cin >> mi >> mj;
        join(mi, mj);
    }

    // 查两个元素是否在同一个集合
    for (int i=1;i<=p;i++) {
        cin >> pi >> pj;
        if(f(pi)==f(pj))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }




    return 0;
}
