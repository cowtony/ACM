class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(nums.size());
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 and dp[i].size() <= dp[j].size()) {
                    dp[i] = dp[j];
                }
            }
            // Keep the max_lenght result.
            dp[i].push_back(nums[i]);
            if (dp[i].size() > res.size()) {
                res = dp[i];
            }
        }
        
        return res;
    }
};
