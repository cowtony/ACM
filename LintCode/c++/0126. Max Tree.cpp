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

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        // Only monotonic decrease can keep the maximum node in stack.
        vector<TreeNode*> s; // Monotonic decrease stack.
        for (int a : A) {
            TreeNode* node = new TreeNode(a);
            while (!s.empty() and a > s.back()->val) {
                node->left = s.back(); // Keep update left until the correct one reach.
                s.pop_back();
            }
            if (!s.empty()) {
                s.back()->right = node;
            }
            s.push_back(node);
        }
        return s.front();
    }
};
