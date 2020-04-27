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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        vector<TreeNode*> layer;
        if (root) {
            layer.emplace_back(root);
        }
        while (!layer.empty()) {
            vector<int> layer_ans;
            vector<TreeNode*> next_layer;
            for (TreeNode* node : layer) {
                layer_ans.emplace_back(node->val);
                if (node->left) {
                    next_layer.emplace_back(node->left);
                }
                if (node->right) {
                    next_layer.emplace_back(node->right);
                }
            }
            layer = next_layer;
            ans.emplace_back(layer_ans);
        }
        return ans;
    }
};
