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
     * @param root: a binary tree
     * @param sum: the sum
     * @return: the scheme
     */
    vector<vector<int>> pathSum(TreeNode * root, int sum) {
        dfs(root, {}, 0, sum);
        return res;
    }
    
    vector<vector<int>> res;
    void dfs(TreeNode* node, vector<int> path, int sum, int target) {
        if (!node) {
            return;
        }
        path.push_back(node->val);
        sum += node->val;
        if (!node->left and !node->right) {
            if (sum == target) {
                res.push_back(path);
            }
            return;
        }
        dfs(node->left, path, sum, target);
        dfs(node->right, path, sum, target);
    }
};
