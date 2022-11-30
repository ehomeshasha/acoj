#include <iostream>

/**
 * 笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。
 */

using namespace std;

/**
 * 求解质数方法
 * @param n
 * @return
 */
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    /**
     * 首先编写质数方法is_prime
     *
     * maxn是单词中出现次数最多的字母的出现次数
     * minn是单词中出现次数最少的字母的出现次数
     * 如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word
     */

    // 输入是一个单词， 只能小写26个字母
    char input[99];
    int a[26] = {0};
    cin >> input;
    for (int i = 0; i < 100; i++) {
        if (input[i] == '\0') {
            break;
        }
        char c = input[i];
        // 小写字母是97~122的ASCII编码
        if (c >= 'a' && c <= 'z') {
            int c_index = c - 'a';
            a[c_index] += 1; // 字母出现次数+1
        }
    }

    int maxn = 0, minn = 99;
    for (int i = 0; i < 26; i++) {
        if (a[i] == 0) {
            // 未出现过忽略
            continue;
        }
        if (a[i] > maxn) {
            maxn = a[i];
        }
        if (a[i] < minn) {
            minn = a[i];
        }
    }

    int res = maxn - minn;
    if (is_prime(res)) {
        cout << "Lucky Word" << endl;
        cout << res << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }





    return 0;
}
