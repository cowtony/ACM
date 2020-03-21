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
    bool isValidBST(TreeNode* root, int64_t minimum = INT64_MIN, int64_t maximum = INT64_MAX) {
        if (!root) {
            return true;
        }
        if (root->val >= maximum or root->val <= minimum) {
            return false;
        }
        return isValidBST(root->left, minimum, root->val) and isValidBST(root->right, root->val, maximum);
    }
};
