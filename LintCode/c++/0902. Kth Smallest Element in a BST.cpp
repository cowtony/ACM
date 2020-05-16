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
void dfsInOrder(TreeNode* root, std::function<void(TreeNode*)> func) {
    if (!root) { return; }
    if (root->left) { dfsInOrder(root->left, func); }
    func(root);
    if (root->right) { dfsInOrder(root->right, func); }
}


class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
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
