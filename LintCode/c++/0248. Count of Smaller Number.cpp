struct SegmentTreeN {
    int start, end;
    int count = 0;
    SegmentTreeN *left, *right;
};

SegmentTreeN* build(int start, int end) {
    if (start > end) {
        return nullptr;
    }
    SegmentTreeN *root = new SegmentTreeN{start, end};
    if (start < end) {
        root->left = build(start, (start + end) / 2);
        root->right = build((start + end) / 2 + 1, end);
    }
    return root;
}

void update(SegmentTreeN* root, int a) {
    if (root == nullptr) {
        return;
    }
    if (root->start > a or root->end < a) {
        return;
    }
    root->count++;
    if (!root->left and !root->right) {
        return;
    }
    if (a <= root->left->end) {
        update(root->left, a);
    } else {
        update(root->right, a);
    }
}

int query(SegmentTreeN* root, int q) {
    if (root == nullptr) {
        return 0;
    }
    if (root->start == q and root->end == q) {
        return root->count;
    }
    if (root->left->end >= q) {
        return query(root->left, q);
    } else {
        return root->left->count + query(root->right, q);
    }
}

class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        SegmentTreeN* root = build(0, 10000);
        for (int a : A) {
            update(root, a);
        }
        vector<int> res;
        for (int q : queries) {
            res.push_back(query(root, q - 1));
        }
        return res;
    }
};
