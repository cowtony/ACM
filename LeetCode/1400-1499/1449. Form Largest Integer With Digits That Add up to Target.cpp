class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, -1); // store max_digit_count for cost i.
        dp[0] = 0;
        for (int t = 1; t <= target; t++) {
            for (int i = 0; i < 9; i++) {
                if (t >= cost[i] and dp[t - cost[i]] >= 0) {
                    dp[t] = max(dp[t], 1 + dp[t - cost[i]]);
                }
            }
        }
        if (dp[target] < 0) return "0";
        string res;
        for (int i = 8; i >= 0; i--) {
            while (target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
                res += '1' + i;
                target -= cost[i];
            }
        }
        return res;
    }
};
