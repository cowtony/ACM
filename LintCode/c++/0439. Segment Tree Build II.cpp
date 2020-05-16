/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        return dfs(A, 0, A.size() - 1);
    }
    
    SegmentTreeNode* dfs(vector<int> &A, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        SegmentTreeNode* root = new SegmentTreeNode(start, end, 0);
        if (start < end) {
            root->left = dfs(A, start, (start + end) / 2);
            root->right = dfs(A, (start + end) / 2 + 1, end);
            root->max = max(root->left->max, root->right->max);
        } else {
            root->max = A[start];
        }
        return root;
    }
};
