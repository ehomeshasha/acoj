#include <iostream>

using namespace std;
int main()
{
    int n, biggest = -2147483648;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > biggest) {
            biggest = tmp;
        }
    }

    cout << biggest << endl;


    return 0;
}
