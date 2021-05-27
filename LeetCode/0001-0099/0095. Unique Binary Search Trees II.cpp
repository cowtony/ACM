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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0] = {nullptr};
        dp[1] = {new TreeNode(1)};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (TreeNode* left : dp[j]) {
                    for (TreeNode* right : dp[i - j - 1]) {
                        TreeNode* root = new TreeNode(j + 1);
                        dp[i].emplace_back(root);
                        root->left = left;
                        root->right = clone(right, j + 1);
                    }
                }
            }
        }
        return dp[n];
    }
    
    TreeNode* clone(TreeNode* node, int offset) {
        if (!node) {
            return nullptr;
        }
        TreeNode* clone_node = new TreeNode(node->val + offset);
        clone_node->left = clone(node->left, offset);
        clone_node->right = clone(node->right, offset);
        return clone_node;
    }
};
 
/* Recursive.
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int from, int to) {
        if (from == to) {
            return {new TreeNode(from)};
        }
        if (to < from) {
            return {nullptr};
        }

        vector<TreeNode*> ans;
        for (int val = from; val <= to; val++) {
            vector<TreeNode*> lefts = generateTrees(from, val - 1);
            vector<TreeNode*> rights = generateTrees(val + 1, to);
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) {
                    TreeNode* root = new TreeNode(val);
                    root->left = left;
                    root->right = right;
                    ans.emplace_back(root);
                }
            }
        }
        return ans;
    }
};
*/
