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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subTreeSum(root);

        vector<int> result;
        for (auto [sum, count] : sum_count) {
            if (count == max_count) {
                result.push_back(sum);
            }
        }
        return result;
    }

    unordered_map<int, int> sum_count;
    int max_count = 0;
    int subTreeSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = root->val + subTreeSum(root->left) + subTreeSum(root->right);
        sum_count[sum]++;
        max_count = max(max_count, sum_count[sum]);
        return sum;
    }
};
