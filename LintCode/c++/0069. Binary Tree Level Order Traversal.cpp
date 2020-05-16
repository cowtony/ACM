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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
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
