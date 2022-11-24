#include <iostream>

using namespace std;
int main()
{
    /**
     * 针对电脑输入的n个整数，计算这些整数的绝对值的和。

        输入格式:

        输入有n+1行，每行一个整数。第一行的整数表示整数的总个数，n<100,。第2~n+1行的数为这n个具体的整数a1~an，这n个整数的值都在-10000到10000之间。
        输出格式:

        输出只有一行，一个整数，为这n个整数的绝对值的和。

     */

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (number < 0) {
            number = - number;
        }
        sum += number;
    }

    cout << sum << endl;

    return 0;
}
