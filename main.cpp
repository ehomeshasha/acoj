#include <iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;
    bool is_fushu = false;
    if (N < 0) {
        is_fushu = true;
    }
    if (is_fushu) {
        N = -N;
    }
    bool first_zero = true;

    if (is_fushu) {
        cout << "-";
    }
    for (int i = 1;; i = i * 10) {
        if (N < i) {
            break;
        }
        int n = N % (i * 10) / i; // n是分离出的位数， 从个位开始
        if (n != 0) {
            first_zero = false;
        }
        if (!first_zero) {
            cout << n;
        }
    }

    return 0;
}


