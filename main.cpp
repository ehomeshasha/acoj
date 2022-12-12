#include <iostream>

using namespace std;

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

int deQueue(SingleLinkedList &list) {
    if (isEmpty(list)) {
        throw bad_exception();
    }
    int value = list.front->data;
    if (list.front == list.rear) {
        list.front = list.rear = nullptr;
    } else {
        list.front = list.front->next;
    }
    list.realSize--;
    return value;
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

bool isFind(SingleLinkedList &list, int value) {
    Node* node = list.front;
    while(node != nullptr) {
        if (value == node->data) {
            return true;
        }
        node = node->next;
    }
    return false;
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
            if (isEmpty(list)) {
                continue;
            }
            deQueue(list);
        }
    }

    Node* node = list.front;
    while(node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;

    return 0;
}
