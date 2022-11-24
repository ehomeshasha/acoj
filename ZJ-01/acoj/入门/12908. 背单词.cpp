#include <iostream>

using namespace std;
int main()
{
    /**
     * 题目内容
     * 啊哈沃德学英语遇到了一些问题，背过的单词老是忘记了，他现在想确定一下碰到的不认识的单词是否是他背过的单词，所以他把背过n个单词记到本子上，有m个不认识的单词，对于每一个不认识的单词查看一下单词本，如果背过输出“Yes”,如果没有背过输出“No”。

        输入格式:

        第一行输入n，第二行输入n个单词，单词之间用空格隔开。
        第三行输入m，第四行输入m个单词，单词之间用空格隔开。
        输出格式:

        输出m行，对于每个不认识的单词，如果背过输出“Yes”,如果没有背过输出“No”。
        限制:

        n<=100
        单词长度不超过30
        样例 1 :

        输入:
        3
        in at on
        2
        for in
        输出:
        No
        Yes


        分析：
        m没有设置上限，因此可能有非常多的字母需要识别，性能需要重点考虑

        英文单词只有26个字母大小写，一共52个字母，每个字母都可以0-52之间的数字
        假设单词长度不超过30， 那么最多需要90数位的整数，目前没有这么大的整数，最大为2147483647，十位数
        也不可能搞这么大的桶，因此桶思路不可行

        但是可以用二维数组思路
        每个单词的每个字母存起来， 然后按顺序逐个比较字母， 如果遇到不同就退出

        输入m个单词，每个单词转化为 m个字母， 逐个比较m个字母
     */
    int n;
    int a[30][52][100] = {0};
    int m;
    char b[100][30]; // 按照i存储单词
    /**
     * 构建单词本思路
     * 分析
     * 按顺序逐个比较字母
     * 那么最快方式就是按照字典方式
     * 把输入的n个单词按照字母逐个建立索引, 一共52个字母， 52*30 = 每个单词需要1560个索引
     *
     * 构建三维字典
     *
     */
    cin >> n;
    for (int i = 0; i < n; i++) {
        char input[30];
        cin >> input;
        for (int j = 0; j < 30; j++) {
            // 到结尾break
            if (input[j] == '\0') {
                break;
            }
            // 遍历单词每个字母
            int index = 0;
            char c = input[j];

            // 存储每个字母
            b[i][j] = c;

            if (c >= 65 && c < 65+26) {
                // 大写字母
                index = c - 65;
            } else if (c >= 97 && c < 97+26) {
                // 小写字母
                index = c - 97 + 26;
            }
            for (int l = 0;; l++) {
                if (a[j][index][l] == 0) {
                    a[j][index][l] = i + 1;
                    break;
                }
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        char input[30];
        cin >> input;

        bool is_words_match = true;

        int match_index_out[100] = {0};

        for (int j = 0; j < 30; j++) {
            // 到结尾break
            if (input[j] == '\0') {
                break;
            }
            // 针对某个单词， 对每个字母的匹配结果进行输出
            int match_index[100] = {0};
            int inc = 0;


            // 按顺序逐个比较字母
            // 先将字符转为index
            int index = 0;
            char c = input[j];
            if (c >= 65 && c < 65+26) {
                // 大写字母
                index = c - 65;
            } else if (c >= 97 && c < 97+26) {
                // 小写字母
                index = c - 97 + 26;
            }

            /**
             * 开始查字典逻辑
             * 逐个比较字母
             * 判断字符是否匹配
             * 第一次匹配的单词结果
             */
            for (int k = 0;;k++) {
                if (a[j][index][k] == 0) {
                    break;
                }
                match_index[inc] = a[j][index][k]; // 这个是能够匹配的单词b_index
                inc++;
            }

            if (inc == 0) {
                // 单个字母里面完全没有匹配的，单词在字典中找不到， 不匹配
                is_words_match = false;
                break;
            }

            // 如果有匹配到的， 对比上一次匹配的结果，从上一次匹配结果里面去除这次里面没有的
            int match_count = 0;

            if (j == 0) {
                // 如果是第一个字母，直接赋值即可，后边字母才需要比较逻辑
                for (int y = 0; y < 100; y++) {
                    if (match_index[y] == 0) {
                        break;
                    }
                    match_index_out[y] = match_index[y];
                    match_count++;
                }
            } else {


                for (int x = 0; x < 100; x++) {
                    if (match_index_out[x] == 0) {
                        break;
                    }
                    if (match_index_out[x] == -1) {
                        continue;
                    }
                    bool is_out_match = false;
                    for (int y = 0; y < 100; y++) {
                        if (match_index[y] == 0) {
                            break;
                        }
                        if (match_index_out[x] == match_index[y]) {
                            match_count++;
                            is_out_match = true;
                        }
                    }
                    if (!is_out_match) {
                        // 过滤掉该单词
                        match_index_out[x] = -1;
                    }
                }
            }
            if (match_count == 0) {
                is_words_match = false;
                break;
            }

            // 判断匹配的字符长度是否有和input字符长度相等的， 如果一个相等的都没有则输出false
            bool is_length_match = false;
            for (int z = 0; z < 100; z++) {
                if (match_index_out[z] == 0) {
                    break;
                }
                if (match_index_out[z] == -1) {
                    continue;
                }
                int cnt1 = 0;
                for (int w = 0;; w++) {
                    if (b[match_index_out[z] - 1][w] == '\0') {
                        break;
                    }
                    cnt1++;
                }
                int cnt2 = 0;
                for (int v = 0;; v++) {
                    if (input[v] == '\0') {
                        break;
                    }
                    cnt2++;
                }
                if (cnt1 == cnt2) {
                    is_length_match = true;
                }
            }

            if (!is_length_match) {
                is_words_match = false;
                break;
            }

        }

        if (!is_words_match) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }


    return 0;
}
