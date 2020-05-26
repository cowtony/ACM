class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int num : nums) {
            target += num;
        }

        if (target % 2 == 1) {
            return false;
        }
        target /= 2;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] or dp[i - num];
            }
        }

        return dp[target];
    }
};
