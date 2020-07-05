template<class T = int>
class SegmentTree {
public:
    SegmentTree(int start, int end, T data = T()) {
        root = build(start, end, data);
    }
    void update(int a, T data = T()) { update(root, a, data); }
    T query(int start, int end) { return query(root, start, end); }
    
private:
    struct Node {
        int start, end;
        T data; // min, max, count, etc.
        Node *left = nullptr, *right = nullptr;
    }*root;
    
    static Node* build(int start, int end, T default_data) {
        if (start > end) {
            return nullptr;
        }
        Node *root = new Node{start, end, default_data};
        if (start < end) {
            root->left = build(start, (start + end) / 2, default_data);
            root->right = build((start + end) / 2 + 1, end, default_data);
        }
        return root;
    }
    
    static void update(Node* root, int pos, T data) {
        if (!root or root->start > pos or root->end < pos) { return; }

        root->data += data;  // Modify this.
        if (!root->left and !root->right) {
            return;
        }
        if (pos <= root->left->end) {
            update(root->left, pos, data);
        } else if (pos >= root->right->start) {
            update(root->right, pos, data);
        }
    }
    
    static T query(Node* root, int start, int end) {
        if (!root) { return T(); }
        if (start <= root->start and end >= root->end) {
            return root->data;
        }
        if (start > root->end or end < root->start) {
            return T(); // sum.
        }
        T left = query(root->left, start, end);
        T right = query(root->right, start, end);
        
        return left + right; // sum range.
        // return max(left, right); // get max.
        // return min(left, right); // get min.
    }
};
