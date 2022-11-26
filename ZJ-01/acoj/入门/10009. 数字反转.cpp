#include <iostream>

using namespace std;
int main()
{
    int x;
    cin >> x;
    bool stop = false;
    int j;
    int abs_x = x;
    int is_negative = false;
    if (x < 0) {
        is_negative = true;
        abs_x = -x;
    }
    int n[10] = {0};
    for (int i = 1;; i *= 10) {
        if (i > abs_x) {
            break;
        }
        int sw = abs_x % (i * 10) / i;
        n[j] = sw;
        j++;
    }

    if (is_negative) {
        cout << "-";
    }

    bool start_zero = true;

    for (int i = 0; i <= 9; i++) {
        if (start_zero && n[i] == 0) {
            continue;
        }
        if (n[i] == -1) {
            continue;
        }
        cout << n[i];
        start_zero = false;
    }
    cout << endl;

    return 0;
}
