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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* root = nullptr;
        for (int val : preorder) {
            TreeNode* node = new TreeNode(val);
            if (s.empty()) {
                root = node;
            } else if (val < s.top()->val) {
                s.top()->left = node;
            } else {
                TreeNode* last_node;
                while (!s.empty() and val > s.top()->val) {
                    last_node = s.top();
                    s.pop();
                }
                last_node->right = node;
            }
            s.push(node);
        }
        return root;
    }
};
