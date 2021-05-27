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
    int answer;
    bool result;
    void DFS(TreeNode* root, int sum)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (sum + root->val == answer)
                result = true;
            return;
        }

        if(result ==false && root->left != NULL)
            DFS(root->left,  sum + root->val);
        if(result ==false && root->right != NULL)
            DFS(root->right, sum + root->val);

    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        answer = sum;
        result = false;
        if (root == NULL)
            return false;
        DFS(root, 0);
        return result;
    }
};
