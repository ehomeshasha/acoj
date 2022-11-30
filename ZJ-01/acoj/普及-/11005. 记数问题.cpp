#include <iostream>

using namespace std;
/**
 * 试计算在区间 1 到 n 的所有整数中,数字 x(0 ≤ x ≤ 9)共出现了多少次?例如,在 1 到 11 中,即在 1、2、3、4、5、6、7、8、9、10、11 中,数字 1 出现了 4 次。

输入格式:

输入共 1 行,包含 2 个整数 n、x,之间用一个空格隔开。
输出格式:

输出共 1 行,包含一个整数,表示 x 出现的次数。
提示:

NOIP 2013 普及组
限制:

对于 100%的数据,1≤ n ≤ 1,000,000,0 ≤ x ≤ 9。
每个测试点1s。
 */


int main()
{

    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        // 分析数位算法
        for (int j = 1;; j*=10) {
            if (j > i) {
                break;
            }
            int sw = i % (10*j)/j;
            if (sw == x) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
