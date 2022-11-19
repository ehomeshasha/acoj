#include <iostream>

using namespace std;
int main()
{
    int x;
    cin >> x;
    int i = 1;
    bool stop = false;
    int tmp;
    int j;
    int abs_x = x;
    int is_negative = false;
    if (x < 0) {
        is_negative = true;
        abs_x = -x;
    }
    int n[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    while(!stop) {
        tmp = abs_x % (i * 10) / i;
        if (tmp == 0 && i * 10 > abs_x) {
            stop = true;
            continue;
        }
        n[j] = tmp;
        i = i * 10;
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
