class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        vector<long long> dp(2, INT_MIN);
        dp[nums[0] % 2] = nums[0];
        long long result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int parity = nums[i] % 2;
            long long cur = max(dp[parity] + nums[i], dp[1 - parity] - x + nums[i]);
            result = max(result, cur);
            dp[parity] = max(dp[parity], cur);
        }
        return result;
    }
};
