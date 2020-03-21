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
    void recoverTree(TreeNode* root) {
        // Morris Traversal (preorder):
        while (root) {  
            if (!root->left) {  
                action(root);
                root = root->right;  
            } else {  
                TreeNode* current = root->left;  
                while (current->right && current->right != root) {
                    current = current->right;  
                }  
                if (current->right) { 
                    action(root);
                    current->right = nullptr;  
                    root = root->right;  
                } else {  
                    current->right = root;
                    root = root->left;  
                }  
            }  
        }
        swap(first->val, second->val);
    }
    
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* pre_node = nullptr;
    void action(TreeNode* node) {
        if (pre_node and pre_node->val > node->val) {
            if (!first) {
                first = pre_node;
            }
            second = node;
        }
        pre_node = node;
    }
};
