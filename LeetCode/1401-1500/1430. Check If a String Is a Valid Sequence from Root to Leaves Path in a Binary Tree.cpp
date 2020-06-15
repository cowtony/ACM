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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        dfs(root, arr, 0);
        return ret;
    }
    
    bool ret = false;
    void dfs(TreeNode* root, const vector<int>& arr, int idx) {
        if (idx >= arr.size()) {
            return;
        }
        if (!root) {
            return;
        }
        if (root->val != arr.at(idx)) {
            return;
        }
        if (idx == arr.size() - 1 and !root->left and !root->right) {
            ret = true;
            return;
        }
        
        dfs(root->left, arr, idx + 1);
        dfs(root->right, arr, idx + 1);
    }
};
