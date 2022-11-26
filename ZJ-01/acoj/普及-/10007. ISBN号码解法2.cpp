#include <iostream>

using namespace std;
int main()
{
    /**
     * 每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位识别码和3位分隔符，其规定格式如“x-xxx-xxxxx-x”，其中符号“-”就是分隔符（键盘上的减号），最后一位是识别码，例如0-670-82162-4就是一个标准的ISBN码。ISBN码的首位数字表示书籍的出版语言，例如0代表英语；第一个分隔符“-”之后的三位数字代表出版社，例如670代表维京出版社；第二个分隔符后的五位数字代表该书在该出版社的编号；最后一位为识别码。
　　识别码的计算方法如下：
　　首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果mod 11，所得的余数即为识别码，如果余数为10，则识别码为大写字母X。例如ISBN号码0-670-82162-4中的识别码4是这样得到的：对067082162这9个数字，从左至右，分别乘以1，2，...,9,再求和，即0×1+6×2+……+2×9=158，然后取158 mod 11的结果4作为识别码。
　　你的任务是编写程序判断输入的ISBN号码中识别码是否正确，如果正确，则仅输出“Right”；如果错误，则输出你认为是正确的ISBN号码。


     */

    char a[9];
    int cal_res = 0;
    char check_code;
    char right_check_code;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &check_code);

    for (int i = 0; i < 9; i++) {
        cal_res += (a[i] - '0') * (i + 1);
    }

    if (cal_res % 11 == 10) {
        right_check_code = 'X';
    } else {
        right_check_code = cal_res % 11 + '0';
    }

    if (check_code == right_check_code) {
        cout << "Right" << endl;
        return 0;
    }

    printf("%c-%c%c%c-%c%c%c%c%c-%c", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], right_check_code);

    return 0;
}
