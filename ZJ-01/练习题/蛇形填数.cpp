#include <iostream>
#include <algorithm>

using namespace std;

/**
蛇形填数
输入两个整数 n 和 m ，输出一个 n 行 m 列的矩阵，将数字 1 到 n × m 按照回字蛇形填充至矩阵中。
具体矩阵形式可参考样例。

输入格式：
输入共一行，包含两个整数 n 和 m 。

输出格式：
输出满足要求的矩阵。
矩阵占 n 行，每行包含 m 个空格隔开的整数。

数据范围：
1 ≤ n, m ≤ 100

输入样例：
3 3

输出样例：
1 2 3
8 9 4
7 6 5
 */

int main()
{

    int n, m;
    cin >> n >> m;
    int q[101][101];
    int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

    // 起始 x 和 y 在 (0, 0)，并且 d 为 0，对应着 x 不动，y 往右走
    int x = 0, y = 0, d = 0;

    for (int i = 1; i <= n * m; i++) {
        q[x][y] = i;

        // 计算 a, b 的下一个位置
        int a = x + dx[d], b = y + dy[d];

        // 判断是否超限
        // 这里 q[a][b] 其实有一层妙用，由于全局数组是被初始化 0 的，
        // 只要填过数，q[a][b] 就必定为真
        if (a < 0 || a >= n || b < 0 || b >= m || q[a][b]) {
            // 移动到下一个位置，% 4 获取 [0, 3] 下标
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }

        // 将正确的 a b 赋给 x y
        x = a, y = b;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << q[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
