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
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeRecursive(inorder, postorder, 0, 0, inorder.size());
    }
    
    TreeNode* buildTreeRecursive(vector<int>& inorder, 
                                 vector<int>& postorder, 
                                 int in_idx, int post_idx, int length) {
        for (int i = 0; i < length; i++) {
            if (inorder[in_idx + i] == postorder[post_idx + length - 1]) {
                TreeNode *root = new TreeNode(inorder[in_idx + i]);
                root->left = buildTreeRecursive(inorder, postorder, in_idx, post_idx, i);
                root->right = buildTreeRecursive(inorder, postorder, in_idx + i + 1, post_idx + i, length - i - 1);
                return root;
            }
        }
        return nullptr;
    }
};
