/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        while (node) {
            Node* copy_node = new Node(node->val);
            copy_node->next = node->next;
            node->next = copy_node;
            node = copy_node->next;
        }
        
        node = head;
        while (node) {
            Node* copy_node = node->next;
            if (node->random) {
                copy_node->random = node->random->next;
            }
            node = copy_node->next;
        }
        
        Node* const dummy_head = new Node(0);
        Node* new_node = dummy_head;
        
        node = head;
        while (node) {
            Node* copy_node = node->next;
            new_node->next = copy_node;
            node->next = copy_node->next;
            node = node->next;
            new_node = new_node->next;
        }
        
        new_node = dummy_head->next;
        delete dummy_head;
        return new_node;
    }
};
