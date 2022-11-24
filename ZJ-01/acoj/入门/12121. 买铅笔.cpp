#include <iostream>

using namespace std;
int main()
{
    int n, m, p;
    cin >> n;
    int min_price;
    for (int i = 0; i < 3; i++) {
        cin >> m >> p;
        // 需要铅笔包装数量
        int k = n / m;
        if (n % m != 0) k++;
        if (i == 0) {
            min_price = k * p;
        } else {
            if (k * p < min_price) {
                min_price = k * p;
            }
        }
    }

    cout << min_price << endl;

    return 0;
}
