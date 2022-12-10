#include <iostream>
#include <string>
using namespace std;

/**
小哼正在学习队列，初始时有一个空的队列，有两种操作。I和O，I（insert）表示要往队尾插入一个元素，O（out）表示删除队首元素。
①I val 往队列末尾里加入一个权值为 val 的元素。
②O 删除队列里最前面元素。
如果操作②的队列是空的，不执行删除操作。

输入格式:

第1行有一个整数n
接下来n行
I val 往队列末尾里加入一个权值为 val 的元素。
O 删除队首元素
输出格式:

输出队列当中最后留下的数
限制:

50%  1<=n<=10000
100% 1<=n<=100000
样例 1 :

输入:
10
I 2
I 1
I 4
O
I 2
I 6
I 1
O
O
O
输出:
6 1
 */

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* front;
    Node* rear;
    int realSize;
};



bool isEmpty(LinkedList& list) {
    return list.front == nullptr && list.rear == nullptr;
}

void enQueue(LinkedList& list, int value) {
    Node* node = new Node{value, nullptr};
    if (isEmpty(list)) {
        list.front = list.rear = node;
    } else {
        list.rear->next = node;
        list.rear = node;
    }
    list.realSize++;
}

int deQueue(LinkedList& list) {
    if (list.front == nullptr) {
        return -1;
    }
    int res = list.front->data;
    if(list.front == list.rear) {
        list.front = list.rear = nullptr;
    } else {
        list.front = list.front->next;
    }
    list.realSize--;
    return res;
}



int main()
{
    int n;
    cin >> n;
    LinkedList list = {nullptr, nullptr, 0};
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == 'I') {
            int val;
            cin >> val;
            enQueue(list, val);
        } else if (op == 'O') {
            deQueue(list);
        }
    }

    Node* node = list.front;
    for (int i = 0;;i++) {
        if (node == nullptr) {
            break;
        }
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;

    return 0;
}
