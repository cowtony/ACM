/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> mapping;
        mapping[node] = new Node(node->val);
        mapping[node]->neighbors.reserve(node->neighbors.size());

        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();

            for (Node* neighbor : n->neighbors) {
                if (mapping.count(neighbor) == 0) {
                    mapping[neighbor] = new Node(neighbor->val);
                    mapping[neighbor]->neighbors.reserve(n->neighbors.size());
                    q.push(neighbor);
                }
                mapping[n]->neighbors.push_back(mapping[neighbor]);
            }
        }
        return mapping[node];
    }
};
