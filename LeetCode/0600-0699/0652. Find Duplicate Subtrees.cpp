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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postOrderTraversal(root);
        return {result.begin(), result.end()};
    }

    unordered_set<TreeNode*> result;
    unordered_map<string, TreeNode*> hash;
    string postOrderTraversal(TreeNode* node) {
        if (!node) {
            return "";
        }
        string left = postOrderTraversal(node->left);
        string right = postOrderTraversal(node->right);
        string traversal =  left + "," + right + "," + to_string(node->val);
        
        if (hash.find(traversal) != hash.end()) {
            result.insert(hash[traversal]);
        } else {
            hash[traversal] = node;
        }
        return traversal;
    }
};
