#include <iostream>

using namespace std;
int main()
{
    int x;
    cin >> x;
    int abs_x = x;
    int is_negative = false;
    if (x < 0) {
        is_negative = true;
        abs_x = -x;
    }

    if (is_negative) {
        cout << "-";
    }

    bool start_zero = true;

    for (int i = 1;; i *= 10) {
        if (i > abs_x) {
            break;
        }
        int sw = abs_x % (i * 10) / i;
        if (sw != 0) {
            start_zero = false;
        } else {
            if (start_zero) {
                continue;
            }
        }
        cout << sw;
    }

    cout << endl;

    return 0;
}
