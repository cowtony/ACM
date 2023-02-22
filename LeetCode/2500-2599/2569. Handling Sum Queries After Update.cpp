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


class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long sum_2 = 0;
        for (int num : nums2) {
            sum_2 += num;
        }
        
        SegmentTree seg_tree(0, nums1.size() - 1, nums1);
        
        vector<long long> result;
        for (const auto& query : queries) {
            if (query[0] == 1) {
                seg_tree.update(query[1], query[2], 0);
            } else if (query[0] == 2) {
                sum_2 += seg_tree.query(0, nums1.size() - 1) * (long long)query[1];
            } else if (query[0] == 3) {
                result.push_back(sum_2);
            }
        }
        return result;
    }
};
