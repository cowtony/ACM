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
    int longestZigZag(TreeNode* root) {
        int max_zigzag = 0;
        dfs(root, max_zigzag);
        return max_zigzag;
    }
    
    pair<int, int> dfs(TreeNode* node, int& max_zigzag) {
        if (!node) {
            return {-1, -1};
        }

        auto [l_left, l_right] = dfs(node->left, max_zigzag);
        auto [r_left, r_right] = dfs(node->right, max_zigzag);
        max_zigzag = max({max_zigzag, l_right + 1, r_left + 1});
        return {l_right + 1, r_left + 1};
    }
};
