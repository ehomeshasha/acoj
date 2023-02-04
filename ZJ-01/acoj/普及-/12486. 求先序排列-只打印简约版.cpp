#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/**
给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度<=8）。
输入格式:
2行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。
输出格式:
1行，表示一棵二叉树的先序。
样例 1 :
输入:
BADC
BDCA
输出:
ABCD
 */
void dfs(string inOrder, string postOrder)
{
    int len=inOrder.length();
    if (len>0) {
        char root=postOrder[len-1];
        cout << root;
        int find_i=inOrder.find(root);
        dfs(inOrder.substr(0,find_i), postOrder.substr(0,find_i));
        dfs(inOrder.substr(find_i+1,len-find_i-1), postOrder.substr(find_i,len-find_i-1));
    }
}


int main()
{
    string inOrder,postOrder;
    cin >> inOrder >> postOrder;
    dfs(inOrder,postOrder);
    cout << endl;

    return 0;
}
