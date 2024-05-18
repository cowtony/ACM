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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        countCoins(root, moves);
        return moves;
    }

    pair<int, int> countCoins(TreeNode* node, int& moves) {
        if (!node) {
            return {0, 0};
        }

        auto [l_node, l_coins] = countCoins(node->left, moves);
        auto [r_node, r_coins] = countCoins(node->right, moves);

        moves += abs(l_node - l_coins) + abs(r_node - r_coins);

        return {l_node + r_node + 1, l_coins + r_coins + node->val};
    }
};
