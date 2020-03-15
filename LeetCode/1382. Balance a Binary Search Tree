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
    vector<int> value;
    TreeNode* balanceBST(TreeNode* root) {
        BST2SortedArray(root);
        return sortedArray2BalancedBST(0, value.size() - 1);
    }
    
    void BST2SortedArray(TreeNode* root) {
        if (!root) {
            return;
        }
        BST2SortedArray(root->left);
        value.push_back(root->val);
        BST2SortedArray(root->right);
    }
    
    TreeNode* sortedArray2BalancedBST(int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        int mid = (lo + hi) / 2;
        TreeNode* root = new TreeNode(value[mid]);
        root->left = sortedArray2BalancedBST(lo, mid - 1);
        root->right = sortedArray2BalancedBST(mid + 1, hi);
        return root;
    }
};
