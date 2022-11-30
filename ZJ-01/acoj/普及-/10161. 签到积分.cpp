#include <iostream>

/**
 * 每天签到一个应用程序，至少可以得 1分，若前一天也签到了，则当天得分为前一天的得分加 1，一天最多只能得 5分。
给定一个只由Y和N 构成的字符序列，该序列表示小爱每天签到的情况，签到记为 Y，没到记为N。请统计小爱能够获得的总积分。


 */

using namespace std;
int main()
{
    int last_score = 0;
    int total_score = 0;
    for (int i = 0;; i++) {
        int input = getchar();

        if (input == EOF) {
            break;
        }

        int today_score;
        if (input == 'Y') {
            // 签到
            today_score = last_score + 1;
            if (today_score > 5) {
                today_score = 5;
            }

        }
        if (input == 'N') {
            // 未签到
            today_score = 0;
        }
        total_score += today_score;
        last_score = today_score;
    }

    cout << total_score << endl;


    return 0;
}
