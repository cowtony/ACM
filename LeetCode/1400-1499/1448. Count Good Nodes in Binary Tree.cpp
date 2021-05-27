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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    
    int dfs(TreeNode* root, int max_val) {
        if (!root) {
            return 0;
        }
        int sum = root->val >= max_val? 1 : 0;
        max_val = max(max_val, root->val);
        sum += dfs(root->left, max_val);
        sum += dfs(root->right, max_val);
        return sum;
    }
};
