#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
给定一个只包含加法和乘法的算术表达式,请你编程计算表达式的值。

输入格式:
输入仅有一行,为需要你计算的表达式,表达式中只包含数字、加法运算符“+”和乘法运算符“*”,且没有括号,所有参与运算的数字均为 0 到 2 ^ 31 -1 之间的整数。
输入数据保证这一行只有 0~ 9、+、*这 12 种字符。
输出格式:

输出只有一行,包含一个整数,表示这个表达式的值。注意:当答案长度多于 4 位时,请只输出最后 4 位,前导 0 不输出。
提示:

NOIP普及组2013
限制:

每个测试点1s。
样例 1 :

输入:
1+1*3+4
输出:
8
样例 2 :

输入:
1+1234567890*1
输出:
7891
样例 3 :

输入:
1+1000000003*1
输出:
4
 */


int number_pow(int number, int power) {
    int res = 1;
    for (int i = 0; i < power; i++) {
        res *= number;
    }
    return res;
}

int to_int(const string& str) {
    unsigned long len = str.length();
    int res = 0;
    for (int i = 0; i < len; i++) { // 12345
        res += (str[i]-'0')*number_pow(10, len-i-1);
    }
    return res;
}



int getRealSize(const int* number) {
    int size = 0;
    for (int i = 0;;i++) {
        if (number[i] == -1) {
            break;
        }
        size++;
    }
    return size;
}

vector<string> splitStr(string str, char c) {
    string temp_str;
    vector<string> res_vector;
    unsigned long len = str.length();
    for (int i = 0; i < len+1; i++) {
        if (str[i] != c && str[i] != '\0') {
            temp_str += str[i];
        } else {
            res_vector.push_back(temp_str);
            temp_str = "";
        }
    }
    return res_vector;
}

int shorterNumber(int number) {
    int no_output_zero = true;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int power = 4-i-1;
        int divider = number_pow(10, power);
        int sw = number/divider%10;
        if (sw != 0) {
            no_output_zero = false;
        }
        if (sw == 0 && no_output_zero) {
            continue;
        }
        res += sw * divider;
    }
    return res;
}

int main()
{
    string input_str;
    cin >> input_str;

    vector<string> plus_vector = splitStr(input_str, '+');
    int plus_res = 0;
    for (int i = 0; i < plus_vector.size(); i++) {
        string str = plus_vector[i];
        vector<string> multi_vector = splitStr(str, '*');
        int multi_res = 1;
        for (int j = 0; j < multi_vector.size(); j++) {
            // 计算乘法结果, 需要考虑上限问题
            multi_res = shorterNumber(multi_res * shorterNumber(to_int(multi_vector[j])));
        }
        // 需要考虑上限问题
        plus_res = shorterNumber(plus_res+shorterNumber(multi_res));
    }

    cout << shorterNumber(plus_res) << endl;

    return 0;
}
