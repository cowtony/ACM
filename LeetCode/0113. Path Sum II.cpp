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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, {}, 0, sum);
        return res;
    }
    
    vector<vector<int>> res;
    void dfs(TreeNode* node, vector<int> path, int sum, int target) {
        if (!node) {
            return;
        }
        path.push_back(node->val);
        sum += node->val;
        if (!node->left and !node->right) {
            if (sum == target) {
                res.push_back(path);
            }
            return;
        }
        dfs(node->left, path, sum, target);
        dfs(node->right, path, sum, target);
    }
};
