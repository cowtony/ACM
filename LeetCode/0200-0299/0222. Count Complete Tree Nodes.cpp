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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int d = 0;
        TreeNode* node = root;
        while (node) {
            d++;
            node = node->left;
        }
        
        int lo = 0, hi = (1 << (d - 1)) - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (exist(root, d, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return (1 << (d - 1)) - 1 + (lo + 1);
    }
    
    bool exist(TreeNode* root, int depth, int idx) {
        for (int i = 1 << (depth - 2); i; i >>= 1) {
            if (i & idx) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};
