/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(nullptr); // identifier for one layer finished.
        Node* previous = nullptr;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node) {
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
                node->next = previous;
            } else {
                q.push(nullptr);
                if (q.front() == nullptr) {
                    break;
                }
            }
            previous = node;
        }
        return root;
    }
};
