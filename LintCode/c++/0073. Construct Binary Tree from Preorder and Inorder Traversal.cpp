/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
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
