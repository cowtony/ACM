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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummyRoot = new TreeNode(0, root, nullptr);
        dfs(dummyRoot, val, depth);
        return dummyRoot->left;
    }

    void dfs(TreeNode* node, int val, int depth) {
        if (depth == 1) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
            return;
        }

        if (node->left) {
            dfs(node->left, val, depth - 1);
        }
        if (node->right) {
            dfs(node->right, val, depth - 1);
        }
    }
};
