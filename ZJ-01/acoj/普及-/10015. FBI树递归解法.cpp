#include <math.h>
#include <stdio.h>

/**
 *              1 0 0 0 1 0 1 1
 *  先转化为串值  I B B B I B I I    第一层
 *              \/  \/  \/  \/
 *              F   B   F   I      第二层
 *               \/      \/
 *               F       F         第三层
 *                  \/
 *                  F              第四层
 *
 *  1. 递归可以让代码一直走
 *  2. return可以让其结束
 *
 *  第一次到底
 *  left_recursive 0, 0 -> left_recursive 1, 0 -> left_recursive 2, 0 ->left_recursive 3, 0
 *  left = 'I'
 *  right_recursive 3, 1 直接一次就到底了返回B
 *  right = 'B'
 *  第一轮打印出 'I' 和 'B'
 *  接着往下走， 计算出组合值为 F, F恰巧就是 left_recursive 2, 0的结果， 就是第二层的最左边的F
 *  打印出第二层的 'F'
 *  接着往下走， 计算 right_recursive 2, 1 ， 因为没有到底， 所以继续下探到下一层 -> left_recursive 3, 2
 *  left = 'B'
 *  right_recursive 3, 3
 *  打印出了第一层第3、4个字符 'B' 'B'
 *  然后接着往下走， 计算出组合值为B， B恰巧就是 right_recursive 2, 1 的结果， 就是第二层第2个字符 'B'
 *  接着往下走， 计算出组合值为 'F'， F恰巧就是 left_recursive 1, 0的结果
 *  以此类推
 *  打印出结果
 *
 *
 *
 */


char recursive(int layer, int index, int n, char *c) {
    if(layer == n) {
        char leaf = (c[index]=='0') ? 'B' : 'I';
        return leaf;
    }
    char left = recursive(layer+1, 2*index, n, c);
    printf("%c", left);
    char right = recursive(layer+1, 2*index+1, n, c);
    printf("%c", right);
    return (left==right && left!='F') ? left : 'F';
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    int count = pow(2, n);
    char c[count];
    for(int i=0; i<count; i++) scanf("%c", &c[i]);
    printf("%c", recursive(0, 0, n, c));
    return 0;
}
