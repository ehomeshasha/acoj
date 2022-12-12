#include <iostream>

using namespace std;

/**

 */
struct Node {
    int data;
    Node* next;
};

struct SingleLinkedList {
    Node* front;
    Node* rear;
    int realSize;
};

bool isEmpty(SingleLinkedList &list) {
    return list.front == nullptr;
}

int size(SingleLinkedList &list) {
    return list.realSize;
}

void enQueue(SingleLinkedList &list, int value) {
    Node* node = new Node{value, nullptr};
    if (list.front == nullptr && list.rear == nullptr) {
        list.front = list.rear = node;
    } else {
        list.rear->next = node;
        list.rear = node;
    }
    list.realSize++;
}

int deQueue(SingleLinkedList &list) {
    if (isEmpty(list)) {
        return -123456789;
    }
    int value = list.front->data;
    if (list.front == list.rear) {
        // 只剩一个
        list.front = list.rear = nullptr;
    } else {
        list.front = list.front->next;
    }
    list.realSize--;
    return value;
}

int* toArray(SingleLinkedList &list) {
    int* a = new int[list.realSize];
    Node* currentNode = list.front;
    int i = 0;
    while(currentNode != nullptr) {
        int data = currentNode->data;
        currentNode = currentNode->next;
        a[i] = data;
        i++;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    SingleLinkedList list = {nullptr, nullptr, 0};

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == 'I') {
            int value;
            cin >> value;

            enQueue(list, value);
        } else if (op == 'O') {
            deQueue(list);
        }
    }

    int* arr = toArray(list);
    for (int i = 0; i < list.realSize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
