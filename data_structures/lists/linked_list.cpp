#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node (int _value): value(_value), next(nullptr) {}
    Node (int _value, Node* _next): value(_value), next(_next) {}
};

class SinglyLinkedList {
public:
    // O(n), O(n)
    Node* create(int data[], int size) {
        Node* pointer = head;
        for (int iterator = 0; iterator < size; ++iterator) {
            if (!pointer) {
                head = new Node(data[iterator]);
                pointer = head;
            } else {
                pointer->next = new Node(data[iterator]);
                pointer = pointer->next;
            }
        }

        return head;
    }

    // O(n), O(1)
    Node* search(int data) {
        Node* pointer = head;
        while (pointer) {
            if (pointer->value == data) {
                return pointer;
            }

            pointer = pointer->next;
        }

        return nullptr;
    }

private:
    Node* head = nullptr;
};


int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SinglyLinkedList list;
    Node* head = list.create(data, sizeof(data) / sizeof(int));

    Node* pointer = head;
    while (pointer) {
        cout << pointer->value << " -> ";
        pointer = pointer->next;
    }
    cout << "null" << endl;

    cout << "search 5: " << list.search(5)->value << endl;
    cout << "search 100: " << list.search(100) << endl;

    return 0;
}