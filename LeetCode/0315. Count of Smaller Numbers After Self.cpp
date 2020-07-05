template<class T = int>
class SegmentTree {
public:
    SegmentTree(int start, int end, T data = T()) {
        root = build(start, end, data);
    }
    void update(int a, T delta = T()) { update(root, a, delta); }
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
    
    static void update(SegmentTreeNode* root, int pos, T delta) {
        if (!root) { return; }
        if (pos < root->start or pos > root->end) {
            return;
        }
        root->data += delta;  // Sum Tree.
        if (!root->left and !root->right) {
            return;
        }
        if (pos <= root->left->end) {
            update(root->left, pos, delta);
        } else if (pos >= root->right->start) {
            update(root->right, pos, delta);
        }
    }
    
    static T query(SegmentTreeNode* root, int start, int end) {
        if (!root) { return T(); }
        if (start <= root->start and end >= root->end) {
            return root->data;
        }
        if (start > root->end or end < root->start) {
            return T(); // Sum Tree.
        }
        T left = query(root->left, start, end);
        T right = query(root->right, start, end);
        return left + right; // Sum Tree.
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Discretization, make the large min-max range to unique limited number.
        int range = discretization(nums);
        
        // Segment tree solution:
        SegmentTree<> tree(0, range);  // Store each unique value's occurance.
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(tree.query(0, nums[i] - 1));
            tree.update(nums[i], 1);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    int discretization(vector<int>& nums) {
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
        return unique;
    }
};
