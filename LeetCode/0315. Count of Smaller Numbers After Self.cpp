template<class R = int, class T = int>  // Range and data.
class SegmentTree {
public:
    SegmentTree(R start, R end, T data = T()) {
        root = build(start, end, data);
    }
    void update(R pos, T delta = T()) { update(root, pos, delta); }
    T query(R start, R end) { return query(root, start, end); }
    
private:
    struct Node {
        R start, end;
        T data; // min, max, count, etc.
        Node *left = nullptr, *right = nullptr;
    }*root;
    
    static Node* build(R start, R end, T default_value) {
        if (start > end) {
            return nullptr;
        }
        Node *root = new Node{start, end, default_value};
        if (start < end) {
            root->left = build(start, start + (end - start) / 2, default_value);
            root->right = build(start + (end - start) / 2 + 1, end, default_value);
        }
        return root;
    }
    
    static void update(Node* root, R pos, T delta) {
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
    
    static T query(Node* root, R start, R end) {
        if (!root) { return T(); }
        if (start <= root->start and end >= root->end) {
            return root->data;
        }
        if (start > root->end or end < root->start) {
            return T(); // Sum Tree.
        }
        return operation(query(root->left, start, end), query(root->right, start, end)); 
    }
    
    static T operation(T left, T right) {
        return left + right; // Sum Tree.
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Discretization, make the large min-max range to unique limited number.
        auto mapping = discretization(nums);
        
        // Segment tree solution:
        SegmentTree<> tree(0, mapping.size());  // Store each unique value's occurance.
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(tree.query(0, mapping[nums[i]] - 1));
            tree.update(mapping[nums[i]], 1);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    unordered_map<int, int> discretization(const vector<int>& nums) {
        vector<int> discrte = nums;
        sort(discrte.begin(), discrte.end());
        unordered_map<int, int> mapping;
        for (int d : discrte) {
            if (mapping.find(d) == mapping.end()) {
                mapping[d] = mapping.size();
            }
        }
        return mapping;
    }
};
