// Segment tree with Lazy Propogation.
class SegmentTree {
public:
    SegmentTree(int start, int end, const vector<int>& data) 
      : kStart(start), kEnd(end) {
        int size = 4 * (end - start + 1);
        tree = vector<int>(size);
        lazy = vector<int>(size);
        build(/*root*/1, start, end, data);
    }
    
    void update(int left, int right, int data) {
        update(left, right, data, /*root*/1, kStart, kEnd);
    }
    int query(int left, int right) {
        return query(left, right, /*root*/1, kStart, kEnd);
    }

private:
    virtual int aggregate(int left, int right) const {
        return left + right;     // Sum Tree
        // return max(left, right); // Max tree
        // return min(left, right); // Min tree
    }

    void build(int node, int start, int end, const vector<int>& data) {
        if (start == end) {  // left node, string the single array element
            tree[node] = data[start - kStart];
            return;
        }
        int mid = (start + end) / 2;
        build(node << 1, start, mid, data);
        build(node << 1 | 1, mid + 1, end, data);
        tree[node] = aggregate(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(int left, int right, int data, int node, int start, int end) {
        lazyPropogation(node, start, end);
        if (end < left || start > right) { return; }
        if (start >= left && end <= right) {
            lazy[node]++;
            lazyPropogation(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(left, right, data, node << 1, start, mid);
        update(left, right, data, node << 1 | 1, mid + 1, end);
        tree[node] = aggregate(tree[node << 1], tree[node << 1 | 1]);
    }

    int query(int left, int right, int node, int start, int end) {
        lazyPropogation(node, start, end);
        if (end < left  ||  start > right) { return 0; }
        if (start >= left && end <= right) { return tree[node]; }
        int mid = (start + end) / 2;
        return aggregate(query(left, right, node << 1, start, mid),
                         query(left, right, node << 1 | 1, mid + 1, end));
    }

    void lazyPropogation(int node, int start, int end) {
        if (lazy[node] == 0) { return; }

        // tree[node] += (end - start + 1) * lazy[node];
        if(lazy[node] & 1)
            tree[node] = (end - start + 1) - tree[node];

        if (start != end) {  // mark both the child (if exist) lazy.
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    const int kStart, kEnd;
    vector<int> tree;  // Store the data for each tree node.
    vector<int> lazy;  // lazy-propogation for range update.
};


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
