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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* dfs(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij) {
        if(pi >= pj or ii >= ij) {
            return nullptr;
        }
            
        TreeNode* root = new TreeNode(preorder[pi]);
        int f = find(inorder.begin() + ii, inorder.begin() + ij, preorder[pi]) - inorder.begin();
        int dis = f - ii;

        root -> left = dfs(preorder, pi + 1, pi + 1 + dis, inorder, ii, ii + dis);
        root -> right = dfs(preorder, pi + 1 + dis, pj, inorder, ii + dis + 1, ij);
        return root;
    }
};
