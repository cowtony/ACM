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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBalancedBST(nums.begin(), nums.end());
    }
    
    template<class Iterator>
    TreeNode* createBalancedBST(const Iterator& begin, const Iterator& end) {
        if (begin == end) {
            return nullptr;
        }
        int size = std::distance(begin, end);
        Iterator mid = std::next(begin, size / 2);
        TreeNode* root = new TreeNode(*mid);
        root->left = createBalancedBST(begin, mid);
        root->right = createBalancedBST(mid + 1, end);
        return root;
    }
};
