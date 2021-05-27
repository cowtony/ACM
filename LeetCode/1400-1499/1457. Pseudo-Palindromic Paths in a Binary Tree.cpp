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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        return dfs(root, count);
    }
    
    int dfs(TreeNode* node, vector<int>& count) {
        if (node == nullptr) {
            return 0;
        }
        
        // Leaf:
        if (!node->left and !node->right) {
            int odd_count = 0;
            count[node->val]++;
            for (int i = 1; i <= 9; i++) {
                if (count[i] % 2 == 1) {
                    odd_count++;
                }
            }
            count[node->val]--;
            return odd_count <= 1? 1 : 0;
        }
        
        count[node->val]++;
        int res = dfs(node->left, count) + dfs(node->right, count);
        count[node->val]--;
        return res;
    }
};
