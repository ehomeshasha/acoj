#include <bits/stdc++.h>


using namespace std;

/**
矩阵 A 规模为 n×m，矩阵 B 规模为 m×p，现需要你求 A×B。
矩阵相乘的定义：n×m 的矩阵与 m×p 的矩阵相乘变成 n×p 的矩阵，令 aik 为矩阵 A 中的元素，bkj 为矩阵 B 中的元素，
则相乘所得矩阵 C 中的元素具体可见样例。
具体可见样例。
输入格式:
第一行两个数 n, m；
接下来 n 行 m 列描述一个矩阵 A；
接下来一行输入 p；
接下来 m 行 p 列描述一个矩阵 B。
输出格式:
输出矩阵 A 与矩阵 B 相乘所得的矩阵 C。
限制:
1≤ n, m, p ≤100
-10000≤ aij, bij ≤10000
样例 1 :
输入:
2 3
1 2 3
3 2 1
2
1 1
2 2
3 3
输出:
14 14
10 10
说明:
14=1×1+2×2+3×3    14=1×1+2×2+3×3
10=3×1+2×2+1×3    10=3×1+2×2+1×3
 */

int main()
{
    int n,m,p,a[105][105],b[105][105],c[105][105];
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> a[i][j];
    cin >> p;
    for(int i=0;i<m;i++)
        for (int j=0;j<p;j++)
            cin >> b[i][j];
    for (int i=0;i<n;i++) {
        for (int k=0;k<p;k++) {
            c[i][k]=0;
            for (int j=0;j<m;j++) {
                c[i][k]+=a[i][j]*b[j][k];
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int k=0;k<p;k++)
            printf("%d ",c[i][k]);
        printf("\n");
    }

    return 0;
}
