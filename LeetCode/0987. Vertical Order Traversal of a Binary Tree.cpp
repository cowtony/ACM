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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (const auto& col : data) {
            vector<int> c;
            for (auto nodes : col.second) {
                for (auto vals : nodes.second) {
                    c.push_back(vals);
                }
            }
            res.push_back(c);
        }
        return res;
    }
    
    map<int, map<int, set<int>, greater<int>>> data; // x, y, values
    void dfs(TreeNode* root, int x, int y) {
        if (!root) {
            return;
        }
        data[x][y].insert(root->val);
        dfs(root->left, x - 1, y - 1);
        dfs(root->right, x + 1, y - 1);
    }
};
