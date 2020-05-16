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
     * @param root: the root of the given tree
     * @return: the values of the nodes you can see ordered from top to bottom
     */
    vector<int> rightSideView(TreeNode * root) {
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
