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
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        return diff;
    }

    void inOrderTraversal(TreeNode* node) {
        if (!node) {
            return;
        }
        inOrderTraversal(node->left);
        diff = min(diff, abs(priv - node->val));
        priv = node->val;
        inOrderTraversal(node->right);
    }

    int diff = INT_MAX, priv = 10000;
};
