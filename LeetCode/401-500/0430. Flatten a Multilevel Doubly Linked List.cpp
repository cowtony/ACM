/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        return helper(head).first;
    }
    
    // Return both head and tail.
    pair<Node*, Node*> helper(Node* head) {
        Node *node = head, *tail = nullptr;
        while (node) {
            if (node->child) {
                Node* temp = node->next;
                node->child->prev = node;
                auto p = helper(node->child);
                node->next = p.first;
                node->child = nullptr;
                
                p.second->next = temp;
                if (temp) {
                    temp->prev = p.second;
                }
                node = p.second;
            }
            
            tail = node;
            node = node->next;
        }
        
        return {head, tail};
    }
};
