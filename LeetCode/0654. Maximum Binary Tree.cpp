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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!s.empty() and num > s.back()->val) {
                node->left = s.back();
                s.pop_back();
            }
            if (!s.empty()) {
                s.back()->right = node;
            }
            s.push_back(node);
        }
        
        if (s.empty()) {
            return nullptr;
        } else {
            return s.front();
        }
    }
};
