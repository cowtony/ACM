/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

template<class T>
class SegmentTree {
public:
    SegmentTree(int start, int end, T data = T()) {
        root = build(start, end, data);
    }
    void update(int a, T data) { update(root, a, data); }
    T query(int start, int end) { return query(root, start, end); }
    
private:
    struct SegmentTreeNode {
        int start, end;
        T data; // min, max, count, etc.
        SegmentTreeNode *left, *right;
    };
    SegmentTreeNode* root;
    
    static SegmentTreeNode* build(int start, int end, T default_value) {
        if (start > end) {
            return nullptr;
        }
        SegmentTreeNode *root = new SegmentTreeNode{start, end, default_value};
        if (start < end) {
            root->left = build(start, (start + end) / 2, default_value);
            root->right = build((start + end) / 2 + 1, end, default_value);
        }
        return root;
    }
    
    static void update(SegmentTreeNode* root, int a, T data) {
        if (!root) { return; }
        if (a < root->start or a > root->end) {
            return;
        }
        root->data = min(root->data, data);
        if (!root->left and !root->right) {
            return;
        }
        if (a <= root->left->end) {
            update(root->left, a, data);
        } else if (a >= root->right->start) {
            update(root->right, a, data);
        }
    }
    
    static T query(SegmentTreeNode* root, int start, int end) {
        if (!root) { return T(); }
        if (start <= root->start and end >= root->end) {
            return root->data;
        }
        if (start > root->end or end < root->start) {
            return INT_MAX;
        }
        T left = query(root->left, start, end);
        T right = query(root->right, start, end);
        return min(left, right);
    }
};

class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: An query list
     * @return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        SegmentTree<int> root(0, A.size(), INT_MAX);
        for (int i = 0; i < A.size(); i++) {
            root.update(i, A[i]);
        }
        vector<int> res;
        for (Interval i : queries) {
            res.push_back(root.query(i.start, i.end));
        }
        return res;
    }
};
