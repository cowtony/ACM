class SegmentTree {
public:
    SegmentTree(int start, int end, int default_val = 0)
      : SegmentTree(start, end, std::vector<int>(end - start + 1, default_val)) {}
      
    SegmentTree(int start, int end, const std::vector<int>& data) 
      : kStart(start), kEnd(end) {
        int size = 4 * (end - start + 1);
        tree = std::vector<int>(size);
        build(/*root*/1, start, end, data);
    }

    void update(int left, int right, int delta) {
        updateInternal(left, right, delta, /*root*/1, kStart, kEnd);
    }

    int query(int left, int right) const {
        return queryInternal(left, right, /*root*/1, kStart, kEnd);
    }

protected:
    void build(int node, int start, int end, const std::vector<int>& data) {
        if (start == end) {  // left node, string the single array element
            tree[node] = data[start - kStart];
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid, data);
        build(node * 2 + 1, mid + 1, end, data);
        tree[node] = aggregate(tree[node * 2], tree[node * 2 + 1]);
    }

    virtual void updateInternal(int left, int right, int delta, int node, int start, int end) {
        if (end < left || start > right) { return; }
        if (start == end) {
            tree[node] += delta;
            return;
        }
        int mid = (start + end) / 2;
        updateInternal(left, right, delta, node * 2, start, mid);
        updateInternal(left, right, delta, node * 2 + 1, mid + 1, end);
        tree[node] = aggregate(tree[node * 2], tree[node * 2 + 1]);
    }

    virtual int queryInternal(int left, int right, int node, int start, int end) const {
        if (end < left || start > right) { return 0; }
        if (start >= left && end <= right) { return tree[node]; }
        int mid = (start + end) / 2;
        return aggregate(queryInternal(left, right, node * 2, start, mid),
                         queryInternal(left, right, node * 2 + 1, mid + 1, end));
    }

    int aggregate(int left, int right) const {
        // return left + right; // Sum Tree
        return max(left, right); // Max tree
        // return min(left, right); // Min tree
    }

    const int kStart, kEnd;
    std::vector<int> tree;  // Store the data for each tree node.
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegmentTree st(0, heights.size() - 1, heights);

        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]) {
                result[i] = b;
            } else {
                result[i] = queryBinarySearch(st, b + 1, heights.size() - 1, heights[a]);
            }
        }

        return result;
    }

    int queryBinarySearch(const SegmentTree& st, int left, int right, int target) const {
        if (st.query(left, right) <= target) {
            return -1;
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (st.query(left, mid) > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
