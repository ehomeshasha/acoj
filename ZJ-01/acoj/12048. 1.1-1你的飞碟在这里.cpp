#include <iostream>

using namespace std;
int main()
{
    char group_name[7], star_name[7];
    cin >> group_name >> star_name;
    int s1 = 1;
    for (int i = 0; i < 6; i++) {
        if (group_name[i] != '\0') {
            s1 *= group_name[i] - 64;
        }
    }

    int mod1 = s1 > 0 ? s1 % 47: s1 % 47 + 47;

    int s2 = 1;
    for (int i = 0; i < 6; i++) {
        if (star_name[i] != '\0') {
            s2 *= star_name[i] - 64;
        }
    }

    int mod2 = s2 > 0 ? s2 % 47: s2 % 47 + 47;

    if (mod1 == mod2) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }

    return 0;
}
