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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        pushLeft(root);
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return !s.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        TreeNode* node = s.top();
        s.pop();
        pushLeft(node->right);
        return node;
    }
    
private:
    stack<TreeNode*> s;
    
    void pushLeft(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};
