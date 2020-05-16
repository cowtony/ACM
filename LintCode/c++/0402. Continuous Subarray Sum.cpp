class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        vector<int> sums(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            sums[i + 1] = sums[i] + A[i];
        }
        
        int min_sum = INT_MAX;
        int min_idx;
        int max_diff = INT_MIN;
        vector<int> ret; 
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] - min_sum > max_diff) {
                max_diff = sums[i] - min_sum;
                ret = {min_idx, i - 1};
            }
            if (sums[i] < min_sum) {
                min_sum = sums[i];
                min_idx = i;
            }
        }
        return ret;
    }
};
