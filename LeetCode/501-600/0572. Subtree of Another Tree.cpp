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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s or !t) {
            return !t;
        }
        return identical(s, t) or isSubtree(s->left, t) or isSubtree(s->right, t);
    }
    
    bool identical(TreeNode* s, TreeNode* t) {
        if (!s or !t) {
            return !s and !t;
        }
        if (s->val != t->val) {
            return false;
        }
        return identical(s->left, t->left) and identical(s->right, t->right);
    }
};
