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
    bool isCousins(TreeNode* root, int x, int y) {
        struct Node {
            TreeNode* node;
            int depth = 0;
            TreeNode* parent = nullptr;
        };
        queue<Node> bfs;
        bfs.push({root});
        
        TreeNode *parent_x, *parent_y;
        int depth_x, depth_y;
        while (!bfs.empty()) {
            Node n = bfs.front();
            bfs.pop();
            if (!n.node) {
                continue;
            }
            if (n.node->val == x) {
                depth_x = n.depth;
                parent_x = n.parent;
            } else if (n.node->val == y) {
                depth_y = n.depth;
                parent_y = n.parent;
            }
            bfs.push({n.node->left, n.depth + 1, n.node});
            bfs.push({n.node->right, n.depth + 1, n.node});
        }
        
        return parent_x != parent_y and depth_x == depth_y;
    }
};
