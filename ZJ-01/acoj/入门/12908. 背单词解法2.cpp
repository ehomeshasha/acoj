#include <iostream>

using namespace std;
int main()
{
    int m, n;
    // 单词本a
    char a[100][30];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        char word[30];
        cin >> word;
        bool is_word_match = false;
        for (int j = 0; j < n; j++) {
            int match_count = 0;
            int char_count = 0;
            int k = 0;
            for (;; k++) { // 到结尾了
                if (word[k] == '\0') {
                    break;
                }
                char_count++;
                if (word[k] == a[j][k]) {
                    match_count++;
                }
            }
            // 两者都到结尾且全部都匹配
            if (match_count == char_count && word[k] == '\0' && a[j][k] == '\0') {
                is_word_match = true;
            }
        }
        if (is_word_match) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
