class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        if (A.empty()) {
            return 0;
        }
        int max_length = 1;
        int inc_length = 1;
        int dec_length = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                inc_length++;
            } else {
                inc_length = 1;
            }
            max_length = max(max_length, inc_length);
            if (A[i] < A[i - 1]) {
                dec_length++;
            } else {
                dec_length = 1;
            }
            max_length = max(max_length, dec_length);
        }
        return max_length;
    }
};
