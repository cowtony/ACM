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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        if (n == 1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*> result;

        for (int l = 1; l < n; l += 2) {
            int r = n - l - 1;

            for (TreeNode* node_l : allPossibleFBT(l)) {
                for (TreeNode* node_r : allPossibleFBT(r)) {
                    TreeNode* root = new TreeNode(0, node_l, node_r);
                    result.push_back(root);
                }
            }
        }

        return result;
    }


};
