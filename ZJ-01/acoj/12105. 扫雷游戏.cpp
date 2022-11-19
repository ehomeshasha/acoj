#include <iostream>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[100][100] = {0};
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= m - 1; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                a[i][j] = '*';
            } else {
                a[i][j] = '?';
            }
        }
    }
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= m - 1; j++) {
            if (a[i][j] == '*') {
                cout << '*';
            } else if (a[i][j] == '?') {
                int cnt = 0;
                int new_i, new_j;
                // 上
                new_i = i - 1;
                if (new_i >= 0 && a[new_i][j] == '*') {
                    cnt++;
                }
                // 下
                new_i = i + 1;
                if (new_i <= n - 1 && a[new_i][j] == '*') {
                    cnt++;
                }
                // 左
                new_j = j - 1;
                if (new_j >= 0 && a[i][new_j] == '*') {
                    cnt++;
                }
                // 右
                new_j = j + 1;
                if (new_j <= m - 1 && a[i][new_j] == '*') {
                    cnt++;
                }
                // 左上
                new_i = i - 1;
                new_j = j - 1;
                if (new_i >= 0 && new_j >= 0 && a[new_i][new_j] == '*') {
                    cnt++;
                }
                // 右上
                new_i = i - 1;
                new_j = j + 1;
                if (new_i >= 0 && new_j <= m - 1 && a[new_i][new_j] == '*') {
                    cnt++;
                }
                // 左下
                new_i = i + 1;
                new_j = j - 1;
                if (new_i <= n - 1 && new_j >= 0 && a[new_i][new_j] == '*') {
                    cnt++;
                }
                // 右下
                new_i = i + 1;
                new_j = j + 1;
                if (new_i <= n - 1 && new_j <= m - 1 && a[new_i][new_j] == '*') {
                    cnt++;
                }
                a[i][j] = cnt;
                cout << a[i][j];
            }
            if (j == m - 1) {
                cout << endl;
            }
        }
    }



    return 0;
}
