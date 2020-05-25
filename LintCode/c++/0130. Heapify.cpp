class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int>& A, int root = 0) {
        if (root >= A.size()) {
            return;
        }
        heapify(A, root * 2 + 1);
        heapify(A, root * 2 + 2);
        
        // Move down.
        while (true) {
            int min_idx = root;
            int left = root * 2 + 1;
            if (left < A.size() and A[left] < A[min_idx]) {
                min_idx = left;
            }
            int right = root * 2 + 2;
            if (right < A.size() and A[right] < A[min_idx]) {
                min_idx = right;
            }
            if (min_idx != root) {
                swap(A[min_idx], A[root]);
                root = min_idx;
            } else {
                break;
            }
        }
    }
};
