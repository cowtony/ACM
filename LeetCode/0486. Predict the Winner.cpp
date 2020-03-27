class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // dp[i][len] means if the sub-game is piles from `i` with length `len`, first player will be winning how much.
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, 0));
        
        for (int len = 1; len <= nums.size(); len++) {
            for (int i = 0; i + len <= nums.size(); i++) {
                if (i + 1 < nums.size()) {
                    dp[i][len] = max(nums[i] - dp[i + 1][len - 1], nums[i + len - 1] - dp[i][len - 1]);
                } else {
                    dp[i][len] = nums[i + len - 1] - dp[i][len - 1];
                }
            }
        }
        return dp[0][nums.size()] >= 0;
    }
};
