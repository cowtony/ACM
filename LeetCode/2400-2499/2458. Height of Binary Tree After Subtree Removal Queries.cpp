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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // The max_height BEFORE node i from left->right and right->left.
        vector<int> left(100001);
        max_height = 0;
        preOrder(root, left, 0);

        vector<int> right(100001);
        max_height = 0;
        ReversePreOrder(root, right, 0);

        vector<int> result;
        for (int query : queries) {
            result.push_back(max(left[query], right[query]));
        }
        return result;
    }
    
    int max_height;
    void preOrder(TreeNode* node, vector<int>& max_heights, int depth) {
        if (!node) {
            return;
        }
        max_heights[node->val] = max_height;
        max_height = max(max_height, depth);
        preOrder(node->left, max_heights, depth + 1);
        preOrder(node->right, max_heights, depth + 1);
    }

    void ReversePreOrder(TreeNode* node, vector<int>& max_heights, int depth) {
        if (!node) {
            return;
        }
        max_heights[node->val] = max_height;
        max_height = max(max_height, depth);
        ReversePreOrder(node->right, max_heights, depth + 1);
        ReversePreOrder(node->left, max_heights, depth + 1);
    }
};
