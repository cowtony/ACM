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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        this->startValue = startValue;
        this->destValue = destValue;
        string path;
        dfs(root, path);

        int i = 0;
        for (; i < startPath.length() && i < destPath.length() && startPath[i] == destPath[i]; i++);
        
        return string(startPath.length() - i, 'U') + destPath.substr(i);
    }

    void dfs(TreeNode* node, string& path) {
        if (!node) {
            return;
        }
        if (node->val == startValue) {
            startPath = path;
        }
        if (node->val == destValue) {
            destPath = path;
        }
        if (startPath != "init" && destPath != "init") { // Early break if both node seen.
            return;
        }
        path += 'L';
        dfs(node->left, path);
        path.pop_back();
        path += 'R';
        dfs(node->right, path);
        path.pop_back();
    }

    string startPath = "init";
    string destPath = "init";
    int startValue;
    int destValue;
};
