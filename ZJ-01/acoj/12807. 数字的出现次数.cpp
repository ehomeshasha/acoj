#include <iostream>

using namespace std;
int main()
{
    int n;
    int a[11] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a[tmp] += 1;
    }

    for (int i = 0; i <= 10; i++) {
        if (a[i] != 0) {
            cout << i << " " << a[i] << endl;
        }
    }

    return 0;
}
