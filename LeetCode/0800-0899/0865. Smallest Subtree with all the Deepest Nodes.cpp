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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) {
            return {0, nullptr};
        }
        auto [height_l, next_l] = dfs(node->left);
        auto [height_r, next_r] = dfs(node->right);

        if (height_l == height_r) {
            return {height_l + 1, node};
        } else if (height_l > height_r) {
            return {height_l + 1, next_l};
        } else {
            return {height_r + 1, next_r};
        }

    }
};