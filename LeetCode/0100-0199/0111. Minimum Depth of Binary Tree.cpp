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
    int minDep = 999999;
    void DFS(TreeNode* root, int depth)
    {
        if (root->left == NULL && root->right == NULL)
        {
            minDep = min(minDep, depth);
            return;
        }
        if (root->left)
            DFS(root->left,  depth + 1);
        if (root->right)
            DFS(root->right, depth + 1);
    }
    
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        DFS(root, 1);
        return minDep;
    }
};
