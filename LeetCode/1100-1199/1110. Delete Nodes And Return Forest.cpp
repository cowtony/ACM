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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> deletes(to_delete.begin(), to_delete.end());
        helper(root, deletes, true);
        return res;
    }
    
    vector<TreeNode*> res;
    // Return the new node after delete, which is either node itself or nullptr.
    TreeNode* helper(TreeNode* node, unordered_set<int>& to_delete, bool is_root) {
        if (!node) {
            return nullptr;
        }
        bool del = to_delete.find(node->val) != to_delete.end();
        
        if (!del and is_root) {
            res.push_back(node);
        } 
        node->left = helper(node->left, to_delete, del);
        node->right = helper(node->right, to_delete, del);
        
        if (del) {
            // delete node;
            return nullptr;
        } else {
            return node;
        }
    }
};
