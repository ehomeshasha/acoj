#include <iostream>

using namespace std;

int main() {
    /**
     * 一元 n 次多项式可用如下的表达式表示：
其中，aixi 称为i次项，ai称为i次项的系数。给出一个一元多项式各项的次数和系数，请按照如下规定的格式要求输出该多项式：
1. 多项式中自变量为x，从左到右按照次数递减顺序给出多项式。
2. 多项式中只包含系数不为0 的项。
3. 如果多项式n 次项系数为正，则多项式开头不出现“+”号，如果多项式n 次项系数为负，则多项式以“-”号开头。
4. 对于不是最高次的项，以“+”号或者“-”号连接此项与前一项，分别表示此项系数为正或者系数为负。
     紧跟一个正整数，表示此项系数的绝对值（如果一个高于0 次的项，其系数的绝对值为1，则无需输出1）。
     如果x 的指数大于1，则接下来紧跟的指数部分的形式为“x^b”，其中b 为x 的指数；如果x 的指数为1，则接下来紧跟的指数部分形式为“x”； 如果x 的指数为0，则仅需输出系数即可。
5. 多项式中，多项式的开头、结尾不含多余的空格。
     */



    int n;
    cin >> n;

    for (int i = 0; i < n + 1; i++) {
        int xs;
        cin >> xs;
        int xm = n - i;
        bool is_first_sign = false;
        bool is_print = true;
        bool is_print_xm = true;

        int abs_xs = xs;
        if (xs < 0) {
            abs_xs = -xs;
        }

        if (i == 0) {
            is_first_sign = true;
        }
        if (xm == 0) {
            is_print_xm = false;
        }
        if (xs == 0) {
            is_print = false;
        }

        /**
         * 思路分析
         * 1. 打印逻辑
         * xs = 0不打印
         * 2. 符号位逻辑
         * 如果xs > 0 输出 + ， 否则输出 -
         * 但是如果是第一个符号， 则 + 可以不输出
         * 3. 系数逻辑
         * 系数不为1 或者 最后一个位
         * 需要输出系数
         * 4. 输出x相关逻辑
         *   如果是最后一位，才需要打印x相关
         *   如果位数不为1，才需要打印x的幂
         *
         *
         *
         *
         */





        if (is_print) {
            if (xs > 0) {
                if (!is_first_sign) {
                    cout << "+";
                }
            } else {
                cout << "-";
            }

            if (abs_xs != 1 || xm == 0) {
                cout << abs_xs;
            }


            if (is_print_xm) {
                cout << "x";
                if (xm != 1) {
                    cout << "^" << xm;
                }
            }
        }

    }

    return 0;
}
