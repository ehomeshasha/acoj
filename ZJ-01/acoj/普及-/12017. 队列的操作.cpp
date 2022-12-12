#include <iostream>

using namespace std;

/**
循环数组解法
 */
struct CycleQueue {
    int front;
    int rear;
    int* data;
    int capacity;
    int realSize;
};

bool isFull(CycleQueue &q) {
    return (q.rear+1+q.capacity)%q.capacity == q.front; // 循环队列牺牲一个空间， 满了之后rear+1==front
}

void enQueue(CycleQueue &q, int value) {
    if (isFull(q)) {
        throw bad_exception();
    }
    q.data[q.rear] = value;
    q.rear = (q.rear+1)%q.capacity;
    q.realSize++;
}

int deQueue(CycleQueue &q) {
    if (q.rear == q.front) {
        return -123456789; // 已经空了
    }
    int value = q.data[q.front];
    q.front = (q.front+1)%q.capacity;
    q.realSize--;
    return value;
}

int* toArray(CycleQueue &q) {
    int* arr = new int[q.realSize];
    int j = 0;
    for (int i = q.front; i%q.capacity!=q.rear; i++) {
        arr[j] = q.data[i];
        j++;
    }
    return arr;
}


int main()
{
    int n;
    cin >> n;
    int* data = new int[n];
    CycleQueue queue = {0, 0, data, 100001};

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == 'I') {
            int value;
            cin >> value;

            enQueue(queue, value);
        } else if (op == 'O') {
            deQueue(queue);
        }
    }

    int* arr = toArray(queue);
    for (int i = 0; i < queue.realSize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
