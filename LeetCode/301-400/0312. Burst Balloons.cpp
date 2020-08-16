class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); // Dummy ballon.
        nums.push_back(1); // Dummy ballon.
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, 0));
        
        for (int len = 1; len <= nums.size(); len++) {
            // Next for loop excludes two dummy ballon on each end.
            for (int i = 1; i + len <= nums.size() - 1; i++) {
                int max_score = 0;
                for (int k = i; k < i + len; k++) {
                    max_score = max(max_score, dp[i][k - i] + dp[k + 1][i + len - k - 1] + nums[i - 1] * nums[k] * nums[i + len]);
                }
                dp[i][len] = max_score;
            }
        }
        
        return dp[1][nums.size() - 2];
    }
};
