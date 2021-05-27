class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        vector<int> dp(nums.size() + 1, 0);
        unordered_map<int, int> prefix_sums;
        prefix_sums[0] = 0;
        int prefix_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            dp[i + 1] = dp[i];
            if (prefix_sums.find(prefix_sum - target) != prefix_sums.end()) {
                dp[i + 1] = max(dp[i + 1], dp[prefix_sums[prefix_sum - target]] + 1);
            }
            prefix_sums[prefix_sum] = i + 1;
        }
        return dp[nums.size()];
    }
};
