template<class T>
class SegmentTree {
public:
    SegmentTree(int start, int end, T data = T()) {
        root = build(start, end, data);
    }
    void update(int a, T data = T()) { update(root, a, data); }
    T query(int start, int end) { return query(root, start, end); }
    
private:
    struct SegmentTreeNode {
        int start, end;
        T data; // min, max, count, etc.
        SegmentTreeNode *left = nullptr, *right = nullptr;
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
    
    static void update(SegmentTreeNode* root, int pos, T data) {
        if (!root) { return; }
        if (pos < root->start or pos > root->end) {
            return;
        }
        root->data ^= data;  // Modify this.
        if (!root->left and !root->right) {
            return;
        }
        if (pos <= root->left->end) {
            update(root->left, pos, data);
        } else if (pos >= root->right->start) {
            update(root->right, pos, data);
        }
    }
    
    static T query(SegmentTreeNode* root, int start, int end) {
        if (!root) { return T(); }
        if (start <= root->start and end >= root->end) {
            return root->data;
        }
        if (start > root->end or end < root->start) {
            return 0; // Modify this.
        }
        T left = query(root->left, start, end);
        T right = query(root->right, start, end);
        return left ^ right; // Modify this.
    }
};

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

class Solution {
public:
    /**
     * @param A: 
     * @param query: 
     * @return: nothing
     */
    vector<int> intervalXOR(vector<int> &A, vector<Interval> &query) {
        vector<int> res;
        SegmentTree<int> stree(0, 1000, 0);
        for (int i = 0; i < A.size(); i++) {
            stree.update(i, A[i]);
        }
        for (Interval interval : query) {
            int num = stree.query(interval.start, interval.start + interval.end - 1);
            res.push_back(num);
        }
        return res;
    }
};
