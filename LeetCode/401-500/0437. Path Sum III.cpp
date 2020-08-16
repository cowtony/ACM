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
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return pathSumFrom(root, sum) 
            + pathSum(root->left, sum) 
            + pathSum(root->right, sum);
    }
    
    int pathSumFrom(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return pathSumFrom(root->left, sum - root->val) 
            + pathSumFrom(root->right, sum - root->val) 
            + (sum == root->val? 1 : 0);
    }
};
