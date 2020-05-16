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
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if (root->end < start or root->start > end) {
            return INT_MIN;
        }
        if (root->start >= start and root->end <= end) {
            return root->max;
        }

        int left = query(root->left, start, end);
        int right = query(root->right, start, end);
        return max(left, right);
    }
};
