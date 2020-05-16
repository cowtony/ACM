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
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int maxPathSum2(TreeNode * root) {
        if (!root) {
            return 0;
        }
        int left = max(0, maxPathSum2(root->left));
        int right = max(0, maxPathSum2(root->right));
        return root->val + max(left, right);
    }
};
