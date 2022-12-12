#include <iostream>

using namespace std;

/**
循环数组解法
 */
struct CycleQueue {
    int* data;
    int front;
    int rear;
    int realSize;
    int capacity;
};

bool isEmpty(CycleQueue &q) {
    return q.front == q.rear;
}

bool isFull(CycleQueue &q) {
    return (q.rear+1)%q.capacity == q.front; // 循环队列牺牲一个空间， 满了之后rear+1==front
}

int deQueue(CycleQueue &q) {
    if (isEmpty(q)) {
        throw bad_exception(); // 已经空了
    }
    int value = q.data[q.front];
    q.front = (q.front+1)%q.capacity;
    q.realSize--;
    return value;
}

void enQueue(CycleQueue &q, int value) {
    if (isFull(q)) {
        throw bad_exception();
    }
    q.data[q.rear] = value;
    q.rear = (q.rear+1)%q.capacity;
    q.realSize++;
}

bool isFind(CycleQueue &q, int value) {
    for (int i = q.front; i!=q.rear; i=(i+1)%q.capacity) {
        if (q.data[i] == value) {
            return true;
        }
    }
    return false;
}


int main()
{
    int n;
    cin >> n;
    int* data = new int[n];
    CycleQueue queue = {data, 0, 0, 0, n+1};

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == 'I') {
            int value;
            cin >> value;

            enQueue(queue, value);
        } else if (op == 'O') {
            if (isEmpty(queue)) {
                continue;
            }
            deQueue(queue);
        }
    }

    for (int i = queue.front; i!=queue.rear; i=(i+1)%queue.capacity) {
        cout << queue.data[i] << " ";
    }

    cout << endl;

    return 0;
}
