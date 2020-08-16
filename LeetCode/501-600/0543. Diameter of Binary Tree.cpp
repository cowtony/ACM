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
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
    
private:
    int diameter = 0;
    
    int depth(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left_depth = depth(node->left);
        int right_depth = depth(node->right);
        diameter = max(diameter, left_depth + right_depth);
        return max(left_depth, right_depth) + 1;
    }
};
