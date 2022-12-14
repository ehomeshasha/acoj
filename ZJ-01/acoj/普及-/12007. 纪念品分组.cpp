#include <iostream>

using namespace std;

/**
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。
为使得参加晚会的同学所获得 的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，
但每组最多只能包括两件纪念品， 并且每组纪念品的价格之和不能超过一个给定的整数。 // 每组纪念品数1~2， 有点像跨步，每次跨1~2步， 每组不能超过上限，例如100
为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。 // 尽量短时间分完， 那么就需要尽量每组都是2个纪念品，先2再1
你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。


输入格式:

输入数据有多组，每组数据包含n+2行：
第1行包括一个整数w，为每组纪念品价格之和的上限。
第2行为一个整数n，表示购来的纪念品的总件数。
第3~n+2行每行包含一个正整数pi (5 <= pi <= w)，表示所对应纪念品的价格。(1<= n <= 30000, 80 <= w <= 200)
输出格式:

仅1行，包含一个整数， ep最少的分组数目合
提示:

noip2007普及组
限制:

50%的数据满足: 1 <=n <= 15
100%的数据满足: 1 <= n <= 30000， 80 <= W <= 200
各个测试点1s
样例 1 :

输入:
100
9
90
20
20
30
50
60
70
80
90
输出:
6
 */

int main()
{
    int w, n;
    cin >> w >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /**
     * 思路
     * 先排序
     * 然后按照从小到大遍历， 为每个小的找出那个较大的和他对应进行配对组合， 一直到匹配不到较大的数， 则后续分组数都是1
     * 所以总分组数 = 总奖品个数 - 能够找到匹配到的次数
     */

    // 80 <= w  <= 200, 5 <= pi <= w, 所以单个礼品价格是5到200的区间内， 直接使用计数排序
    int count[196] = {0}; // 0代表5， 195代表200
    for (int i = 0; i < n; i++) {
        count[a[i]-5]++;
    }
    // 回填数组
    int index = 0;
    for (int i = 0; i < 196; i++) {
        while (count[i] > 0) {
            a[index++] = i+5;
            count[i]--;
        }
    }


    int match_count = 0;
    int min_value = a[0];
    int max_index = 0;
    for (int i = n - 1; i >= 0; i--) { // 从后往前遍历， 如果存在能够<=w的， 表明能够接受的最大index值
        if (min_value + a[i] <= w) {
            max_index = i;
            break;
        }
    }

    for (int i = 0; i < max_index; i++) {
        for (int j = max_index; j >=0; j--) {
            if (i < j && a[i]+a[j] <= w) {
                match_count++;
                max_index--;
                break;
            } else {
                max_index--;
            }
        }
    }


    int res = n - match_count;
    cout << res << endl;

    return 0;
}
