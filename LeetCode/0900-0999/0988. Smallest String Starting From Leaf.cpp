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
    string smallestFromLeaf(TreeNode* root, string str = "") {
        if (!root) {
            return "|";
        }
        str = string(1, 'a' + root->val) + str;

        string result;
        if (!root->left && !root->right) {  // Check if leaf node
            result = str;
        } else {
            result = min(smallestFromLeaf(root->left, str), smallestFromLeaf(root->right, str));
        }
        return result;
    }
};
