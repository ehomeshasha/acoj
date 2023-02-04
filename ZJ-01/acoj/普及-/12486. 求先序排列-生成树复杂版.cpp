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
struct Tree {
    char ch;
    struct Tree *left, *right;
};

Tree* newNode(char ch) {
    Tree *node = (Tree*) malloc(sizeof(Tree));
    node->ch=ch;
    node->left=node->right=NULL;
    return node;
}

// direction=0 向左， direction=1向右
Tree* createTree(string inOrder, string postOrder, Tree* node, int direction)
{
    int len=inOrder.length();
    if (len==0) return node;
    char root=postOrder[len-1];
    Tree* nd=newNode(root);
    if (node==NULL) node=nd;
    else {
        if (direction==0) node->left = nd;
        if (direction==1) node->right = nd;
    }
    int find=0;
    for (int i=0;i<len;i++)
        if (inOrder[i]==root) find=i;
    string inOrderLeft=inOrder.substr(0,find);
    string postOrderLeft=postOrder.substr(0,find);
    createTree(inOrderLeft,postOrderLeft, nd,0);
    string inOrderRight=inOrder.substr(find+1,len-find-1);
    string postOrderRight=postOrder.substr(find,len-find-1);
    createTree(inOrderRight,postOrderRight,nd,1);
    return node;
}

void preOrderTree(Tree* node) {
    if (node) {
        printf("%c", node->ch);
        preOrderTree(node->left);
        preOrderTree(node->right);
    }
}


int main()
{
    string inOrder,postOrder;
    cin >> inOrder >> postOrder;
    Tree* node=createTree(inOrder,postOrder,NULL,-1);
    preOrderTree(node);




    return 0;
}
