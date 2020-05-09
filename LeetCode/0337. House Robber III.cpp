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
        int rob, not_rob;
        dfs(root, rob, not_rob);
        return max(rob, not_rob);
    }
    
    void dfs(TreeNode* root, int& rob, int& not_rob) {
        rob = 0;
        not_rob = 0;
        if (!root) {
            return;
        }
        int rob_left, not_rob_left;
        dfs(root->left, rob_left, not_rob_left);
        int rob_right, not_rob_right;
        dfs(root->right, rob_right, not_rob_right);
        
        rob = root->val + not_rob_left + not_rob_right;
        not_rob = max(rob_left, not_rob_left) + max(rob_right, not_rob_right);
    }
};
