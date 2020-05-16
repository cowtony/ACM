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
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        return max(dfs(root, true), dfs(root, false));
    }

    map<TreeNode*, map<bool, int>> dp;
    int dfs(TreeNode* root, bool rob) {
        if (!root) {
            return 0;
        }
        if (dp.find(root) != dp.end() and dp.at(root).find(rob) != dp.at(root).end()) {
            return dp[root][rob];
        }
        int sum = rob? root->val : 0;
        if (rob) {
            sum += dfs(root->left, false);
            sum += dfs(root->right, false);
        } else {
            sum += max(dfs(root->left, true), dfs(root->left, false));
            sum += max(dfs(root->right, true), dfs(root->right, false));
        }
        dp[root][rob] = sum;
        return sum;
    }
};
