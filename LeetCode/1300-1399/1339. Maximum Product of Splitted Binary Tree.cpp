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
    int maxProduct(TreeNode* root) {
        int sum = sumTree(root);

        uint64_t max_product = 0;
        // No need for binary search since the DFS is already O(n).
        for (int i = 0; i < values.size() - 1; i++) {
            max_product = max(max_product, uint64_t(values[i]) * (sum - values[i]));
        }
        return max_product % 1000000007;
    }

    int sumTree(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int value = node->val + sumTree(node->left) + sumTree(node->right);
        values.push_back(value);
        return value;
    }

    vector<int> values;
};