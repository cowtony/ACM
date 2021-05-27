/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNodeWithCount : public TreeNode {
    int count = 1; // Store the order of this element.
    int val;
    TreeNodeWithCount *left = nullptr;
    TreeNodeWithCount *right = nullptr;
    TreeNodeWithCount(int x) : val(x) {}
};

TreeNodeWithCount* buildTreeWithCount(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNodeWithCount* new_root = new TreeNodeWithCount(root->val);
    new_root->left = buildTreeWithCount(root->left);
    if (new_root->left) {
        new_root->count += new_root->left->count;
    }
    new_root->right = buildTreeWithCount(root->right);
    if (new_root->right) {
        new_root->count += new_root->right->count;
    }
    return new_root;
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNodeWithCount* node = buildTreeWithCount(root);

        while (node) {
            int left_count = node->left? node->left->count : 0;
            if (k <= left_count) {
                node = node->left;
            } else if (k == left_count + 1) {
                return node->val;
            } else {
                k -= left_count + 1;
                node = node->right;
            }
        }
        return -1;
    }
};
