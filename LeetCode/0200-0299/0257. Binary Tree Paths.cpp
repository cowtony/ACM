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
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ret;
    }
    
    vector<string> ret;
    void dfs(TreeNode* node, string path) {
        if (node == nullptr) {
            return;
        }
        if (!node->left and !node->right) {
            ret.push_back(path + to_string(node->val));
            return;
        }
        dfs(node->left, path + to_string(node->val) + "->");
        dfs(node->right, path + to_string(node->val) + "->");
    }
};
