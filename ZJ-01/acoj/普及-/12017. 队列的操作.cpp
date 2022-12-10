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

struct Queue {
    int* data;
    int front;
    int rear;
    int capacity;
};

bool isEmpty(Queue q) {
    return q.front == q.rear;
}

bool isFull(Queue q) {
    return (q.rear+1+q.capacity)%q.capacity == q.front;
}

void enQueue(Queue &q, int value) {
    if (isFull(q)) {
        q.front = (q.front+1)%q.capacity;
    }
    q.data[q.rear] = value;
    q.rear = (q.rear+1)%q.capacity;
}

int deQueue(Queue &q) {
    if (isEmpty(q)) {
        return -1;
    }
    int res = q.data[q.front];
    q.front = (q.front+1)%q.capacity;
    return res;
}



int main()
{
    int n;
    cin >> n;
    int capacity = 200000;
    int* a = new int(capacity);
    Queue q = {a, 0, 0, capacity};
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == 'I') {
            int val;
            cin >> val;
            enQueue(q, val);
        } else if (op == 'O') {
            deQueue(q);
        }
    }

//     遍历队列
//    for (int i = 0;;i++) {
//        if (isEmpty(q)) {
//            break;
//        }
//        cout << deQueue(q) << " ";
//    }

    for (int i = q.front;i%q.capacity!=q.rear; i++) {
        int output = q.data[i%q.capacity];
        cout << output << " ";
    }

    cout << endl;

    return 0;
}
