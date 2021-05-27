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
    bool DFS(TreeNode* left, TreeNode* right)
    {
        if (left && right)
            return left->val == right->val
                && DFS(left->left, right->right)
                && DFS(left->right, right->left);
        else
            return left == right;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->left && root->right)
            return DFS(root->left, root->right);
        else
            return root->left == root->right;
    }
};
