#include <iostream>

using namespace std;


char convertInput(char input_char) {
    if (input_char == '1') {
        return 'I';
    } else if (input_char == '0') {
        return 'B';
    }
}


char calCombine(char c1, char c2) {
    if (c1 == 'B' && c2 == 'B') {
        return 'B';
    } else if (c1 == 'I' && c2 == 'I') {
        return 'I';
    }
    return 'F';
}

int calPower(int base, int power) {
    int res = 1;
    for (int i = 0; i < power; i++) {
        res *= base;
    }
    return res;
}

typedef char DATA;
struct BinTreeNode {
    DATA value;
    BinTreeNode *left;
    BinTreeNode *right;
};

/**
 * 深度优先遍历
 * 右侧优先
 * @param node
 */
int a_index = 0;
void dfs(BinTreeNode node, char a[]) {
    a[a_index] = node.value;
    a_index++;
    if (node.left == nullptr || node.right == nullptr) {
        return;
    }
    BinTreeNode leftNode = *node.left;
    BinTreeNode rightNode = *node.right;
    dfs(rightNode, a);
    dfs(leftNode, a);
}


int main()
{
    /**
     * 我们可以把由“0”和“1”组成的字符串分为三类：全“0”串称为B串，全“1”串称为I串，既含“0”又含“1”的串则称为F串。
FBI树是一种二叉树1，它的结点类型也包括F结点，B结点和I结点三种。由一个长度为2^N的“01”串S可以构造出一棵FBI树T，递归的构造方法如下：

T的根结点为R，其类型与串S的类型相同；
若串S的长度大于1，将串S从中间分开，分为等长的左右子串S1和S2；由左子串S1构造R的左子树T1，由右子串S2构造R的右子树T2。
现在给定一个长度为2^N的“01”串，请用上述构造方法构造出一棵FBI树，并输出它的后序遍历2序列。
     */



    /**
     * 思路分析
     * 层数是关键，层数记为M（从下往上数）
     * 第一层 - 每2个输出到上层串， 结果为第二层的串值
     * 第二层 - 每2个输出到上层串， 结果为第三层的串值
     * 第n层 ...
     * 最上一层 = N + 1
     *
     *
     *              1 0 0 0 1 0 1 1
     *  先转化为串值  I B B B I B I I    第一层
     *              \/  \/  \/  \/
     *              F   B   F   I      第二层
     *               \/      \/
     *               F       F         第三层
     *                  \/
     *                  F              第四层
     *
     *
     * 深度优先遍历
     *
     * 输入N，则总共有N+1层
     *
     * 定义二叉树结构体
     *
     *
     *
     */

    int N;
    cin >> N;
    char str[1024];
    cin >> str;
    /**
     * 最多11层,
     * 由于N最大为10，所以total最大为2^10=1024
     * 所以构建数组来存储所有的树
     *
     * 第一层
     * 遍历2^N次     2^3
     * 第二层
     * 遍历2^(N-1)次 2^2
     * ...          2^1
     * 第N+1层
     * 遍历2^0=1次   2^0
     *
     */
    BinTreeNode a[11][1024];

    // 遍历N+1
    for (int i = 0; i < N + 1; i++) {
        int power = N - i; // 计算幂
        int loopCount = calPower(2, power);
        for (int j = 0; j < loopCount; j++) {
            // 遍历每一层的节点
            // 如果第一层
            BinTreeNode node {};
            if (i == 0) {
                char c = convertInput(str[j]);
                node.value = c;
                node.left = nullptr;
                node.right = nullptr;
            } else {
                node.left = &a[i-1][j*2];
                node.right = &a[i-1][j*2+1];
                node.value = calCombine(node.left->value, node.right->value);
            }
            a[i][j] = node;
        }

    }



    /**
     * 对二叉树进行后序遍历
     *
     * 递归思想
     *
     * 结果逆序就是正序从右侧进行深度遍历
     * 因此可以先计算正序右侧深度遍历， 然后逆序结果就是想要的
     *
     *              1 0 0 0 1 0 1 1
     *  先转化为串值  I B B B I B I I    第一层
     *              \/  \/  \/  \/
     *              F   B   F   I      第二层
     *               \/      \/
     *               F       F         第三层
     *                  \/
     *                  F              第四层
     *
     *
     * 想要的结果：IBFBBBFIBFIIIFF = 后序左侧遍历
     * 逆序结果： FFIIIFBIFBBBFBI  = 正序右侧遍历
     *
     *
     *
     */

    BinTreeNode topNode = a[N][0];
    char revert_result[1024*11]; // 正序右侧遍历
    dfs(topNode, revert_result);
    // 逆序输出
    int strLen = 0;
    for (int i = 0;; i++) {
        if (revert_result[i] == '\0') {
            strLen = i;
            break;
        }
    }


    for (int i = strLen - 1; i >= 0; i--) {
        cout << revert_result[i];
    }
    cout << endl;


    return 0;
}


