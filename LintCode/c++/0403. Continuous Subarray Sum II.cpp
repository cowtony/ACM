class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        vector<int> sums(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            sums[i + 1] = sums[i] + A[i];
        }
        // Get the maximum subarray
        int min_sum = INT_MAX;
        int min_idx;
        int max_diff = INT_MIN;
        vector<int> max_ret; 
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] - min_sum > max_diff) {
                max_diff = sums[i] - min_sum;
                max_ret = {min_idx, i - 1};
            }
            if (sums[i] < min_sum) {
                min_sum = sums[i];
                min_idx = i;
            }
        }
        // Get the minimum subarray
        int max_sum = -100000;
        int max_idx;
        int min_diff = INT_MAX;
        vector<int> min_ret; 
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] - max_sum < min_diff) {
                min_diff = sums[i] - max_sum;
                min_ret = {max_idx, i - 1};
            }
            if (sums[i] > max_sum) {
                max_sum = sums[i];
                max_idx = i;
            }
        }

        if (max_diff > sums.back() - min_diff) {
            return max_ret;
        } else {
            if (min_ret[0] == 0 and min_ret[1] == A.size() - 1) {
                return max_ret;
            } else {
                return {(min_ret[1] + 1) % A.size(), (min_ret[0] - 1 + A.size()) % A.size()};
            }
        }
    }
};
