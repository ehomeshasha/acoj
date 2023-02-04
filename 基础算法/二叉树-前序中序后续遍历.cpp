#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/**
前序
 ABDHECF
中序
 DHBEAFC
求后序
 HDEBFCA
 */
void dfs(string preOrder,string inOrder) {
    int len=preOrder.length();
    if (len>0) {
        char root=preOrder[0];
        int k=inOrder.find(root);
        dfs(preOrder.substr(1,k),inOrder.substr(0,k));
        dfs(preOrder.substr(k+1,len-k-1),inOrder.substr(k+1,len-k-1));
        cout << root;
    }
}

int main()
{
    string preOrder,inOrder;
    cin >> preOrder >> inOrder;
    dfs(preOrder,inOrder);
    return 0;
}
