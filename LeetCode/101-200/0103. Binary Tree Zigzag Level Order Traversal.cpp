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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        bool right = true;
        stack<TreeNode*> layer;
        if (root) {
            layer.push(root);
        }
        while (!layer.empty()) {
            vector<int> layer_ans;
            stack<TreeNode*> next_layer;
            while (!layer.empty()) {
                TreeNode* node = layer.top();
                layer.pop();
                layer_ans.emplace_back(node->val);
                if (right) {
                    if (node->left) {
                        next_layer.push(node->left);
                    }
                    if (node->right) {
                        next_layer.push(node->right);
                    }
                } else {
                    if (node->right) {
                        next_layer.push(node->right);
                    }
                    if (node->left) {
                        next_layer.push(node->left);
                    }
                }
            }
            layer = next_layer;
            ans.emplace_back(layer_ans);
            right = !right;
        }
        return ans;
    }
};
