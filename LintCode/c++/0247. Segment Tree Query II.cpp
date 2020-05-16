/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if (!root) {
            return 0;
        }
        if (root->end < start or root->start > end) {
            return 0;
        }
        if (root->start >= start and root->end <= end) {
            return root->count;
        }

        int left = query(root->left, start, end);
        int right = query(root->right, start, end);
        return left + right;
    }
};
