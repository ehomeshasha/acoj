#include <iostream>

using namespace std;
int main()
{
    int K, gold = 0, gold_one_day = 1;
    cin >> K;
    int cnt = 0;
    for (int i = 1; i <= K; i++) {
        gold += gold_one_day;
        cnt++;
        if (cnt == gold_one_day) {
            cnt = 0;
            gold_one_day++;
        }
    }
    cout << gold << endl;


    return 0;
}
