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
    //     0
    //    / \
    //   0   1
    //  / \ / \
    // 0  1 2  3
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<tuple<TreeNode*, long double>> bfs;
        bfs.emplace(root, 0);
        bfs.emplace(nullptr, 0);
        
        long double left = 1, right = 0;
        long double res = 1;
        while (!bfs.empty()) {
            auto [node, index] = bfs.front();
            bfs.pop();
            
            if (node == nullptr) {
                bfs.push({nullptr, 0});
                res = max(res, right - left + 1);
                if (get<0>(bfs.front()) == nullptr) {
                    break;
                }
                left = right = get<1>(bfs.front());
                continue;
            }
            // cout << node->val << ' ' << index << endl;
            left = min(left, index);
            right = max(right, index);
            
            if (node->left) {
                bfs.emplace(node->left, index * 2);
            }
            if (node->right) {
                bfs.emplace(node->right, index * 2 + 1);
            }
        }
        return res;
    }
};
