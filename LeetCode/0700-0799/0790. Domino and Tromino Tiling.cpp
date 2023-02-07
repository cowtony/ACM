class Solution {
public:
    int numTilings(int n) {
        vector<int64_t> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        int64_t sum_dp = dp[0] + dp[1];
        for (int i = 2; i <= n; i++) {
            // dp[n] = sum(2 * dp[0], 2 * dp[1], ..., 2 * dp[n - 3]) + dp[n - 2] + dp[n - 1]
            dp[i] = (sum_dp * 2 - dp[i - 2] - dp[i - 1]) % kMod;
            sum_dp += dp[i];
        }
        return dp[n];
    }

    const int64_t kMod = 1000000007;
};