#include <iostream>

using namespace std;
int main()
{
    char a[1000];
    char x;
    cin >> a >> x;
    int y;
    for (int i = 0; i < 1000; i++) {
        if (a[i] == '\0') {
            break;
        }
        if (a[i] == x) {
            y = i + 1;
        }
    }

    cout << y;

    return 0;
}
