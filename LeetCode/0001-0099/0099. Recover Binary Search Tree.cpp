/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void morrisTraversalInOrder(TreeNode* root, std::function<void(TreeNode*)> func) {
    while (root) {  
        if (!root->left) {  
            func(root);
            root = root->right;  
        } else {  
            TreeNode* pre = root->left;  
            while (pre->right && pre->right != root) {
                pre = pre->right;  
            }  
            if (!pre->right) { 
                pre->right = root;
                root = root->left;  
            } else {  
                pre->right = nullptr;  
                func(root);
                root = root->right;  
            }  
        }  
    }
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pre_node = nullptr;
        
        morrisTraversalInOrder(root, [&first, &second, &pre_node](TreeNode* node){
            if (pre_node and pre_node->val > node->val) {
                if (!first) {
                    first = pre_node;
                }
                second = node;
            }
            pre_node = node;
        });
        swap(first->val, second->val);
    }
};
