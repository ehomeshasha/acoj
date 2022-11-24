#include <iostream>

using namespace std;
int main()
{
    int budget[12];
    int left[13];
    int flow_in = 300;
    left[0] = 0;
    int total_save = 0;
    // 录入12个月的预算
    for (int i = 0; i <= 11; i++) {
        cin >> budget[i];
        left[i+1] = left[i] + flow_in - budget[i];
        if (left[i+1] < 0) {
            cout << -(i+1);
            return 0;
        }
        if (left[i+1] >= 100) {
            int temp_save = left[i+1] / 100 * 100;
            left[i+1] = left[i+1] - temp_save;
            total_save += temp_save;
        }
    }

    cout << total_save / 5 * 6 + left[12] << endl;

    return 0;
}
