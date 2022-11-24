#include <iostream>

using namespace std;
int main()
{
    int L, R, cnt = 0;
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        // 分离数位
        int step = 1;
        bool stop = false;
        while(!stop) {
            int tmp = i % (step * 10) / step;
            if (tmp == 2) {
                cnt++;
            }
            if (tmp == 0 && step * 10 > i) {
                stop = true;
            }
            step = step * 10;
        }
    }
    cout << cnt << endl;

    return 0;
}
