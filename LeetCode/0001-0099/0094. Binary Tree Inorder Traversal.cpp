/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    vector<int> ans;
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        ans.emplace_back(root->val);
        dfs(root->right);
    }
};
