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
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        vector<int> path;
        dfs(root, target, 0, path);
        return ret;
    }
    
    vector<vector<int>> ret;
    void dfs(TreeNode* node, int target, int sum, vector<int>& path) {
        if (!node) {
            return;
        }
        path.push_back(node->val);
        sum += node->val;
        if (!node->left and !node->right) {
            if (sum == target) {
                ret.push_back(path);
            }
        }
        dfs(node->left, target, sum, path);
        dfs(node->right, target, sum, path);
        path.pop_back();
    }
};
