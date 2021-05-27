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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        DFS(root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    
    vector<vector<int>> result;
    void DFS(TreeNode* root, int level)
    {
        if (root == NULL)
            return;
        if (result.size() <= level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        DFS(root->left, level + 1);
        DFS(root->right, level + 1);
    }
};
