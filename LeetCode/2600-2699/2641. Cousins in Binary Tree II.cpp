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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        
        getDepthSum(root, 0);
        setVal(root, 0, root->val);
        return root;
    }
    
    vector<int> sum_for_depth;
    void getDepthSum(TreeNode* node, int depth) {
        if (!node) {
            return;
        }
        if (sum_for_depth.size() <= depth) {
            sum_for_depth.push_back(0);
        }
        sum_for_depth[depth] += node->val;
        
        getDepthSum(node->left, depth + 1);
        getDepthSum(node->right, depth + 1);
    }
    
    void setVal(TreeNode* node, int depth, int neighbor_sum) {
        if (!node) {
            return;
        }
        node->val = sum_for_depth[depth] - neighbor_sum;
        int new_sum = (node->left? node->left->val : 0) 
                    + (node->right? node->right->val : 0);
        setVal(node->left, depth + 1, new_sum);
        setVal(node->right, depth + 1, new_sum);
    }
};
