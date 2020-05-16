/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: the number of nodes
     */
    int getAns(TreeNode * root) {
        dfs(root);
        return count;
    }
    
    int count = 0;
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        count++;
        dfs(root->left);
        dfs(root->right);
    }
};
