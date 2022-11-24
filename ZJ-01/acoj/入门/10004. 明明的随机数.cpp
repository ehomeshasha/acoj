#include <iostream>

using namespace std;
int main() {

    int N;
    cin >> N;
    int arr[1001] = {0};
    int cnt = 0;
    int tmp;

    for (int i = 0; i <= N; i++) {
        cin >> tmp;
        if (arr[tmp] == 0) {
            cnt++;
        }
        arr[tmp] = 1;
    }
    cout << cnt << endl;

    for (int i = 0; i <= 1000; i++) {
        if (arr[i] == 1) {
            cout << i;
        }
    }
    cout << endl;
    return 0;

}

