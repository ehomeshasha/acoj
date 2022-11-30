#include <iostream>
#include <vector>

using namespace std;

void print_match_result(vector<char> input_seq, int win_count) {
    int left_score = 0;
    int right_score = 0;
    int seq_len = input_seq.size();

    if (seq_len == 0) {
        cout << "0:0" << endl;
    }

    for (int i = 0; i < seq_len; i++) {
        char c = input_seq[i];
        if (c == 'W') {
            left_score++;
        } else if (c == 'L') {
            right_score++;
        }
        // 不够细心， 赢球可以左边赢也可以右边赢
        if (((left_score >= win_count && left_score >= right_score + 2) || (right_score >= win_count && right_score >= left_score + 2))) {
            cout << left_score << ":" << right_score << endl;
            left_score = 0;
            right_score = 0;
        }
        // 统计结束，打出当前比赛结果
        if (seq_len - 1 == i) {
            cout << left_score << ":" << right_score << endl;
        }
    }
}


int main()
{
    vector<char> input_seq;

    // 初始化list容量
    for (int i = 0;; i++) {
        int input = getchar();
        if (input == EOF || input == 'E') {
            // 文件结尾或者遇到E跳出循环
            break;
        }
        if (input == '\n' || input == '\r') {
            continue;
        }
        char c = input;
        input_seq.push_back(c);
    }

    print_match_result(input_seq, 11);
    cout << endl;
    print_match_result(input_seq, 21);
    cout << endl;

    return 0;
}
