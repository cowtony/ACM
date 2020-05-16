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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        vector<ListNode*> res;
        while (!q.empty()) {
            queue<TreeNode*> tmp_q;
            ListNode* dummy_root = new ListNode;
            ListNode* node = dummy_root;
            while (!q.empty()) {
                TreeNode* n = q.front();
                q.pop();
                node->next = new ListNode(n->val);
                node = node->next;
                if (n->left) {
                    tmp_q.push(n->left);
                }
                if (n->right) {
                    tmp_q.push(n->right);
                }
            }
            res.push_back(dummy_root->next);
            q = tmp_q;
        }
        return res;
    }
};
