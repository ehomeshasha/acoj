#include <iostream>

using namespace std;
int main()
{
    char c;
    cin >> c;
    // 大写字母
    if (c >= 65 && c <= 90) {
        c += 32;
    } else if (c >= 97 && c <= 122) {
        c -= 32;
    }
    cout << c;

    return 0;
}
