#include <iostream>

using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * 10 + j;
            if (j == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}
