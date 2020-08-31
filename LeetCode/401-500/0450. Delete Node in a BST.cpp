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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val == key) {
            root = deleteRoot(root);
            return root;
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
    
    TreeNode* deleteRoot(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        if (!root->left and !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            return root->right;
        } else if (!root->right) {
            return root->left;
        } else {
            TreeNode* node = root->right;
            while (node->left) {
                node = node->left;
            }
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
            return root;
        }
    }
};
