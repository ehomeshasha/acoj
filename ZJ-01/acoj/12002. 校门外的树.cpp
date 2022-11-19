#include <iostream>

using namespace std;
int main()
{
    int L, M, s, e;
    cin >> L >> M;

    int a[10001] = {0};
    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        cin >> s >> e;
        for (int j = s; j <= e; j++) {
            a[j] = 1;
        }
    }

    for (int i = 0; i <= L; i++) {
        if (a[i] != 1) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
