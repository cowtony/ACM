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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    TreeNode* buildTree(vector<int>::const_iterator inorder_begin, 
                        vector<int>::const_iterator inorder_end, 
                        vector<int>::const_iterator postorder_begin,
                        vector<int>::const_iterator postorder_end) {
        if (inorder_begin == inorder_end or postorder_begin == postorder_end) {
            return nullptr;
        }
        
        int root_val = *(postorder_end - 1);
        int i = 0;
        for (auto it = inorder_begin; it != inorder_end; it++, i++) {
            if (*it == root_val) {
                return new TreeNode(root_val, 
                                    buildTree(inorder_begin, inorder_begin + i, postorder_begin, postorder_begin + i),
                                    buildTree(inorder_begin + i + 1, inorder_end, postorder_begin + i, postorder_end - 1));
            }
        }
        return nullptr;
    }
};
