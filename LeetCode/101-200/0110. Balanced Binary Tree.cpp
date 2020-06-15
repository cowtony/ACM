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
    bool flag = true;
    
    int Depth(TreeNode* root)
    {
        if (flag ==false)
            return 0;
        
        if (root == NULL)
            return 0;
        
        int left = Depth(root->left);
        int right = Depth(root->right);
        
        if (left - right > 1 || right - left > 1)
            flag = false;
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        Depth(root);
        return flag;
    }
};
