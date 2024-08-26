/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) {
            return {};
        }

        vector<int> result;
        for (Node* child : root-> children) {
            auto vec = postorder(child);
            result.insert(result.end(), vec.begin(), vec.end());
        }
        result.push_back(root->val);
        return result;
    }
};
