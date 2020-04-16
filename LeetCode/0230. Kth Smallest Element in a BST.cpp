/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfsInOrder(TreeNode* root, std::function<void(TreeNode*)> func) {
    if (!root) { return; }
    if (root->left) { dfsInOrder(root->left, func); }
    func(root);
    if (root->right) { dfsInOrder(root->right, func); }
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        int count = 0;
        dfsInOrder(root, [&](TreeNode* node) { 
            count++;
            if (count == k) {
                ret = node->val;
            }
        });
        return ret;
    }
};
