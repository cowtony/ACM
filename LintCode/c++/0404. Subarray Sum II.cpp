class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        vector<int> sums(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            sums[i + 1] = sums[i] + A[i];
        }
        
        int lower = 0, higher = 0, count = 0;
        for (int i = 1; i < sums.size(); i++) {
            while (lower < i and sums[i] - sums[lower] > end) {
                lower++;
            }
            while (higher < i and sums[i] - sums[higher] >= start) {
                higher++;
            }
            count += higher - lower;
        }
        return count;
    }
};
