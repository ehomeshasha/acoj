#include <iostream>

using namespace std;
int main()
{
    int tmp1, tmp2;
    int res = 0;
    int no_happy = 0;
    for (int i = 1; i <= 7; i++) {
        cin >> tmp1 >> tmp2;
        if (tmp1 + tmp2 > 8 && tmp1 + tmp2 > no_happy) {
            no_happy = tmp1 + tmp2;
            res = i;
        }
    }
    cout << res << endl;


    return 0;
}
