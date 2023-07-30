#include <iostream>
using namespace std;


class LinkedList {
public:
    void remove(int idx) {
        if (idx == 0) {
            LinkedListNode* node_to_be_deleted = head;
            head = head->next;
            delete node_to_be_deleted;
            return;
        }

        LinkedListNode *previous_node = head, *node = head;
        for (int i = 0; i < idx; i++) {
            previous_node = node;
            node = node->next;
            if (node == nullptr) {
                return;
            }
        }
        previous_node->next = node->next;
        delete node;
    }

    void push_back(int val) {
        if (head == nullptr) {
            head = new LinkedListNode;
            head->value = val;
            return;
        }

        LinkedListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
        }
        // node is now pointing to the last node.
        node->next = new LinkedListNode;
        node = node->next;
        node->value = val;
    }

    int size() {
        LinkedListNode* node = head;
        int result = 0;
        while (node != nullptr) {
            result++;
            node = node->next;
        }
        return result;
    }

    void print() {
        LinkedListNode* node = head;
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

private:
    struct LinkedListNode {
        int value = -1;
        LinkedListNode* next = nullptr;
    };

    LinkedListNode* head = nullptr;
};

int main() {
    LinkedList l_list;

    cout << l_list.size() << endl;  // 0
    l_list.push_back(1);
    cout << l_list.size() << endl;  // 1
    l_list.push_back(2);
    l_list.print();  // 1, 2
    l_list.remove(0);
    l_list.print();  // 2

    for (int v : {4,6,8,10}) {
        l_list.push_back(v);
    }
    l_list.print();

    return 0;
}
