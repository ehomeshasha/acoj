#include <iostream>

using namespace std;
int main()
{
    /**
     * 都是正整数，所以可以用计数排序搞定
     * 订正：注意题目中有个隐含处理， 如果数字重复，需要在输出时也重复输出
     */
    int n;
    int a[100000] = {0};
    cin >> n;

    // 循环n次
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a[input] += 1;
    }

    for (int i = 0; i < 100000; i++) {
        if (a[i] > 0) {
            for (int j = 0; j < a[i]; j++) {
                cout << i << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
