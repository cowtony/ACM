class Solution {
public:
    /**
     * @param A: an integer array
     * @return: return maxium contiguous non-negative subarray sum
     */
    int maxNonNegativeSubArray(vector<int> &A) {
        int sum = 0, max_sum = -1;
        for (int a : A) {
            if (a >= 0) {
                sum += a;
                max_sum = max(max_sum, sum);
            } else {
                sum = 0;
            }
        }
        return max_sum;
    }
};
