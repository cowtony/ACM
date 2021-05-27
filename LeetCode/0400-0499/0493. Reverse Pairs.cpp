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
    int reversePairs(vector<int>& nums) {
        // return mergeSort(nums.begin(), nums.end());  // MergeSort solution.

        auto mapping = discretization(nums);
        
        SegmentTree<> tree(0, mapping.size(), 0);
        int res = 0;
        for (int j = 1; j < nums.size(); j++) {
            tree.update(mapping[nums[j - 1]], 1);
            res += tree.query(findGreater(mapping, 2L * nums[j]), mapping.size());
        }
        return res;
    }
    
    map<long, int> discretization(const vector<int>& nums) {
        vector<int> discrte = nums;
        sort(discrte.begin(), discrte.end());
        map<long, int> mapping;
        for (int d : discrte) {
            if (mapping.find(d) == mapping.end()) {
                mapping[d] = mapping.size();
            }
        }
        return mapping;
    }
    
    int findGreater(const map<long, int>& mapping, long val) {
        auto it = mapping.upper_bound(val);
        if (it != mapping.end()) {
            return it->second;
        } else {
            return mapping.size();
        }
    }
    
    template<class Iterator>
    long inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end) {
        std::vector<typename Iterator::value_type> temp;
        temp.reserve(std::distance(begin, end));
        Iterator l = begin;
        Iterator r = mid;

        while (l != mid and r != end) {
            if (*r <= *l) { temp.emplace_back(*r++); }
            else { temp.emplace_back(*l++); }
        }
        temp.insert(temp.end(), l, mid);
        temp.insert(temp.end(), r, end);
        
        long ret = 0;
        l = begin;
        r = mid;
        while (l != mid and r != end) {
            while (l != mid and *l <= *r * 2L) {
                l++;
            }
            ret += std::distance(l, mid);
            r++;
        }
        
        std::move(temp.begin(), temp.end(), begin);
        return ret;
    }
    template<class Iterator>
    long mergeSort(const Iterator& begin, const Iterator& end) {
        int size = std::distance(begin, end);   
        if (size <= 1) { return 0; }
        Iterator mid = std::next(begin, size / 2);
        long ret = 0;
        ret += mergeSort(begin, mid); // sort left half
        ret += mergeSort(mid, end); // sort right half
        ret += inplace_merge(begin, mid, end); // merge left and right.
        return ret;
    }
};
