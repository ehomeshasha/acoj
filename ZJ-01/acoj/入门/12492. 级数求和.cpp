#include <iostream>

using namespace std;
int main()
{
    int K, i;
    cin >> K;
    double Sn = 0.0;
    for (i = 1;; i++) {
        Sn += 1.0 / i;
        if (Sn > K) {
            break;
        }
    }
    cout << i << endl;
    return 0;
}
