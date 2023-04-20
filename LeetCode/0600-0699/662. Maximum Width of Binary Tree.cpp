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
    /*
           0
          / \
         0   1        left = root * 2, right = root * 2 + 1
        / \ / \
       0  1 2  3
         /      \
        2        7
       / \      / \
      4   5    14 15  (diff = 15 - 4 = 11)
        0        5    (always set the left most index to 0 would avoid overflow)
       / \      / \
      0   1    10 11  (diff = 11 - 0 = 11)
        
    */
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<pair<TreeNode*, long>> q;
        q.emplace(root, 0);
        q.emplace(nullptr, 0);
        
        long left = 1;
        long res = 1;
        while (!q.empty()) {
            auto [node, index] = q.front();
            q.pop();
            
            if (node == nullptr) {
                q.push({nullptr, 0});
                if (q.front().first == nullptr) {
                    break;
                }
                left = q.front().second;
                continue;
            }
            res = max(res, index - left + 1);
            
            if (node->left) {
                q.push({node->left, (index - left) * 2 + 0});
            }
            if (node->right) {
                q.push({node->right, (index - left) * 2 + 1});
            }
        }
        return res;
    }
};
