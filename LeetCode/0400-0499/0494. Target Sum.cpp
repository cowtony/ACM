class Solution {
public:
    // 1D DP
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || -target > sum) {
            return 0;
        }
        vector<int> dp(sum * 2 + 1, 0);
        dp[0 + sum] = 1;

        for (int num : nums) {
            vector<int> temp(dp.size(), 0);
            for (int t = 0; t <= 2 * sum; t++) {
                if (t + num <= 2 * sum) {
                    temp[t] += dp[t + num];
                }
                if (t - num >= 0) {
                    temp[t] += dp[t - num];
                }
            }
            dp = temp;
        }
        return dp[target + sum];
    }

    // Back tracking with Memorization
    int findTargetSumWays2(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(4000 + 1, -1));

        sort(nums.begin(), nums.end(), less<int>());
        return dfs(nums, 0, target, dp);
    }

    int dfs(const vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
        if (dp[idx][target + 2000] != -1) {
            return dp[idx][target + 2000];
        }

        if (idx == nums.size()) {
            return target == 0? 1 : 0;
        }

        return dp[idx][target + 2000] = dfs(nums, idx + 1, target + nums[idx], dp) 
                                      + dfs(nums, idx + 1, target - nums[idx], dp);
    }
};