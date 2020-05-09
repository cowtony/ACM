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
    int rob(TreeNode* root) {
        return max(dfs(root, true), dfs(root, false));
    }
    
    map<TreeNode*, map<bool, int>> dp;
    int dfs(TreeNode* root, bool rob) {
        if (!root) {
            return 0;
        }
        if (dp.find(root) != dp.end() and dp.at(root).find(rob) != dp.at(root).end()) {
            return dp[root][rob];
        }
        int sum = rob? root->val : 0;
        if (rob) {
            sum += dfs(root->left, false);
            sum += dfs(root->right, false);
        } else {
            sum += max(dfs(root->left, true), dfs(root->left, false));
            sum += max(dfs(root->right, true), dfs(root->right, false));
        }
        dp[root][rob] = sum;
        return sum;
    }
};
