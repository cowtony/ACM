#include <iostream>
using namespace std;


struct LinkedListNode {
    int value = -1;
    LinkedListNode* next = nullptr;
};


void appendNode(LinkedListNode* node, int val) {
    while (node->next != nullptr) {
        node = node->next;
    }
    // node is now pointing to the last node.
    node->next = new LinkedListNode;
    node = node->next;
    node->value = val;
}

void printLinkedList(LinkedListNode* node) {
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}


void deleteLinkedList(LinkedListNode* node) {
    if (node == nullptr) {
        return;
    }

    deleteLinkedList(node->next);
    delete node;
}

int main() {
    LinkedListNode* head = new LinkedListNode;

    for (int val : {2,4,6,3,5,7}) {
        appendNode(head, val);
    }

    printLinkedList(head);

    deleteLinkedList(head);
}
