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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
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
