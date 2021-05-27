class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int dp_max = 0;
        int max_sum = INT_MIN;
        int dp_min = 0;
        int min_sum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (dp_max >= 0) {
                dp_max += A[i];
            } else {
                dp_max = A[i];
            }
            max_sum = max(max_sum, dp_max);
            
            if (dp_min < 0) {
                dp_min += A[i];
            } else {
                dp_min = A[i];
            }
            min_sum = min(min_sum, dp_min);
        }
        
        // Corner case when all number is negative.
        if (max_sum < 0) {
            return max_sum;
        }
        return max(max_sum, sum - min_sum);
    }
};
