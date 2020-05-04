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
        root->data++;  // Modify this.
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
        return left + right; // Modify this.
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Discretization, make the large min-max range to unique limited number.
        vector<int> discrte = nums;
        sort(discrte.begin(), discrte.end());
        int unique = 0;
        map<int, int> m;
        for (int d : discrte) {
            if (m.find(d) == m.end()) {
                m[d] = unique++;
            }
        }
        for (int& num : nums) {
            num = m.at(num);
        }
        
        // Segment tree solution:
        SegmentTree<int> tree(0, unique);
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(tree.query(INT_MIN, nums[i] - 1));
            tree.update(nums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
