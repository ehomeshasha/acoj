#include <iostream>

using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i <= n + 1; i++) {
            if (i == 0) {
                cout << "#";
            } else if (i == n + 1) {
                cout << "#" << endl;
            } else {
                cout << "*";
            }
        }
    }

    return 0;
}
