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
     * @param nums: an array
     * @return: the maximum tree
     */
    TreeNode * constructMaximumBinaryTree(vector<int> &nums) {
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
