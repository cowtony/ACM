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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetricSubTree(root->left, root->right);
    }

    bool isSymmetricSubTree(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 && tree2) {
            return tree1->val == tree2->val
                && isSymmetricSubTree(tree1->left, tree2->right)
                && isSymmetricSubTree(tree1->right, tree2->left);
        } else {
            return tree1 == tree2; // == nullptr
        }
    }
};
