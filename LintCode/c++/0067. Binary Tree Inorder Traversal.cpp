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
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> ans;
        morrisTraversalInOrder(root, [&ans](TreeNode* n){ans.push_back(n->val);});
        return ans;
    }
};
