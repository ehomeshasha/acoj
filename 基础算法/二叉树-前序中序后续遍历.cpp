#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/**
二叉树
输入
ABD###CE##F##
前序
ABDCEF
中序
DBAECF
后序
DBEFCA
 */
typedef struct Tree {
    char ch;
    struct Tree *left, *right;
};

Tree* newNode(char ch)
{
    Tree *t=(Tree*) malloc(sizeof(Tree));
    t->ch=ch;
    t->left=t->right=NULL;
    return t;
}

Tree* create()
{
    char c;
    c=getchar();
    Tree* node=NULL;
    if (c=='#') {
        node=NULL;
    } else {
        node=newNode(c);
        node->left=create();
        node->right=create();
    }
    return node;
}

void preOrder(Tree* root)
{
    if (root) {
        printf("%c ",root->ch);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree* root)
{
    if (root) {
        inOrder(root->left);
        printf("%c ",root->ch);
        inOrder(root->right);
    }
}

void postOrder(Tree* root)
{
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ",root->ch);
    }
}

int main()
{
    Tree* root=create();
    printf("preOrder: ");preOrder(root);printf("\n");
    printf("inOrder: ");inOrder(root);printf("\n");
    printf("postOrder: ");postOrder(root);printf("\n");
    return 0;
}
