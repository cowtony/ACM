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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> layer;
        if (root) {
            layer.push(root);
        }
        while (!layer.empty()) {
            queue<TreeNode*> q;
            while (!layer.empty()) {
                TreeNode* node = layer.front();
                layer.pop();
                if (layer.empty()) {
                    ret.push_back(node->val);
                }
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            layer = q;
        }
        
        return ret;
    }
};
