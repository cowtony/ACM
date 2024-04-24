/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> graph(1e5 + 1);
        buildGraph(graph, root);

        return getHeight(graph, start) - 1;
    }

    void buildGraph(vector<vector<int>>& graph, TreeNode* node, TreeNode* parent = nullptr) {
        if (!node) {
            return;
        }

        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        buildGraph(graph, node->left, node);
        buildGraph(graph, node->right, node);
    }

    int getHeight(const vector<vector<int>>& graph, int node, int parent = -1) {
        int max_height = 0;
        for (int next : graph[node]) {
            if (next != parent) {
                max_height = max(max_height, getHeight(graph, next, node));
            }
        }
        return max_height + 1;
    }
};
