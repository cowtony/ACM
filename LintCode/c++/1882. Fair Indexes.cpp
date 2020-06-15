class Solution {
public:
    /**
     * @param A: an array of integers
     * @param B: an array of integers
     * @return: return a integer indicating the number of fair indexes.
     */
    int CountIndexes(vector<int> &A, vector<int> &B) {
        vector<int> prefix_a(A.size() + 1, 0);
        vector<int> prefix_b(B.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            prefix_a[i + 1] = prefix_a[i] + A[i];
            prefix_b[i + 1] = prefix_b[i] + B[i];
        }
        
        int count = 0;
        for (int i = 1; i < A.size(); i++) {
            if (prefix_a[i] == prefix_a[A.size()] - prefix_a[i] and 
                prefix_b[i] == prefix_b[B.size()] - prefix_b[i] and
                prefix_a[i] == prefix_b[i]) {
                count++;    
            }
        }
        return count;
    }
};
