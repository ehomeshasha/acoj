#include <iostream>

using namespace std;
int main()
{
    int tmp;
    int height[10];
    int taotao_height;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        height[i] = tmp;
    }

    cin >> taotao_height;

    for (int i = 0; i < 10; i++) {
        int h = height[i];
        if (h <= taotao_height + 30) {
            count += 1;
        }
    }

    cout << count;

    return 0;
}
