#include <iostream>

using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int res = A / 10 * 2 + B / 10 * 3 + C / 10 * 5;
    cout << res << endl;
    return 0;
}
