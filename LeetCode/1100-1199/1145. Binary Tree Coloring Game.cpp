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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        children_count = vector<int>(n + 1, 0);
        red = x;
        dfs(root);

        if (children_count[x] <= n / 2) {
            return true;
        } else if (x_node->left && children_count[x_node->left->val] > n / 2) {
            return true;
        } else if (x_node->right && children_count[x_node->right->val] > n / 2) {
            return true;
        } else {
            return false;
        }
    }

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        if (node->val == red) {
            x_node = node;
        }
        return children_count[node->val] = 1 + dfs(node->left) + dfs(node->right);
    }

    vector<int> children_count;
    TreeNode* x_node;
    int red;
};