#include <iostream>
#include <algorithm>

using namespace std;

/**
某人想调查学校OI组每个同学的生日，并按照年龄从大到小的顺序排序。但近作业很多，没有时间，所以请你帮她排序。（1<n<100）

输入格式:

有2行，
第1行为OI组总人数n；
第2行至第n+1行分别是每人的姓名s、出生年y、月m、日d。
输出格式:

有n行，
即n个生日从大到小同学的姓名。如果同年同月同日生则按照姓名的字典序从大到小。
限制:

1<n<100，length(s)<20
样例 1 :

输入:
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1
输出:
Luowen
Yangchu
Qiujingya
 */
int my_str_to_int(string s) {
    int sum = 0;
    int len = s.length();
    int radix = 1;
    for (int i = len-1; i >= 0; i--) {
        sum+=radix*(s[i]-'0');
        radix*=10;
    }
    return sum;
}

int my_compare_str(string s1, string s2) {
    int i1 = my_str_to_int(s1);
    int i2 = my_str_to_int(s2);
    return i1-i2;
}

int my_compare(string* sr1, string* sr2) {
//    if (sr1[1] > sr2[1]) {
//        return 1;
//    }
    int res = my_compare_str(sr1[1], sr2[1]);
    if (res == 0) {
        res = my_compare_str(sr1[2], sr2[2]);
        if (res == 0) {
            res = my_compare_str(sr1[3], sr2[3]);
            if (res == 0) {

            }
        }
    } else {
        return res;
    }


    if (my_compare_str(sr1[1], sr2[1]) == 0) {
        if (my_compare_str(sr1[2], sr2[2]) == 0) {
            if (my_compare_str(sr1[3], sr2[3]) == 0) {

            }
        }
    }
}

int my_swap(string* sr1, string* sr2, string* tmp) {

}

int main()
{
    int n;
    cin >> n;
    string s[100][4];
    string tmp[4];
    for (int i = 0; i < n; i++)
        cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3];

    int test = my_str_to_int(s[0][1]);
    cout << test << endl;
//    for (int i = 0; i < n-1; i++) {
//        for (int j = 0; j < n-1-i; j++) {
//            if (my_compare(s[j], s[j+1]) > 0) {
//                my_swap(s[j], s[j+1], tmp);
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << s[i][0] << endl;
//    }
    return 0;
}
