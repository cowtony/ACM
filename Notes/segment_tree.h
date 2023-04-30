template<class T = int>  // Data.
class SegmentTree {
public:
    SegmentTree(int start, int end, T default_val = T())
      : kStart(start), kEnd(end), tree(4 * (end - start + 1)) {
        build(1, start, end, default_val);
    }

    void update(int pos, T delta = T()) {
        update(1, kStart, kEnd, pos, delta);
    }

    T query(int start, int end) {
        return query(1, kStart, kEnd, start, end);
    }

private:
    void build(int node, int start, int end, T default_val) {
        if (start == end) {
            tree[node] = default_val;
            return;
        }
        int mid = (start + end) / 2;
        build(node << 1, start, mid, default_val);
        build(node << 1 | 1, mid + 1, end, default_val);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void update(int node, int start, int end, int pos, T delta) {
        if (start == end) {
            tree[node] += delta;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update(node << 1, start, mid, pos, delta);
        } else {
            update(node << 1 | 1, mid + 1, end, pos, delta);
        }
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    T query(int node, int start, int end, int q_start, int q_end) {
        if (start >= q_start && end <= q_end) {
            return tree[node];
        }
        if (start > q_end || end < q_start) {
            return T();
        }
        int mid = (start + end) / 2;
        T left_query = query(node << 1, start, mid, q_start, q_end);
        T right_query = query(node << 1 | 1, mid + 1, end, q_start, q_end);
        return left_query + right_query;
    }

    const int kStart, kEnd;
    vector<T> tree;
};


// Segment tree with Lazy Propogation.
class SegmentTree {
public:
    SegmentTree(int start, int end, int default_val = 0)
      : SegmentTree(start, end, vector<int>(end - start + 1, default_val)) {}
      
    SegmentTree(int start, int end, const vector<int>& data) 
      : kStart(start), kEnd(end) {
        int size = 4 * (end - start + 1);
        tree = vector<int>(size);
        lazy = vector<int>(size);
        build(/*root*/1, start, end, data);
    }
    
    void update(int left, int right, int delta) {
        update(left, right, delta, /*root*/1, kStart, kEnd);
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

    void update(int left, int right, int delta, int node, int start, int end) {
        lazyPropogation(node, start, end);
        if (end < left || start > right) { return; }
        if (start >= left && end <= right) {
            lazy[node] += delta;
            lazyPropogation(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(left, right, delta, node << 1, start, mid);
        update(left, right, delta, node << 1 | 1, mid + 1, end);
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

