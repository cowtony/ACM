class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        if ((stones.size() - 1) % (K - 1) != 0) {
            return -1;
        }
        vector<int> sum(stones.size() + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            sum[i + 1] = sum[i] + stones[i];
        }
        
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size() + 1, 0));
        for (int len = K; len <= stones.size(); len++) {
            for (int i = 0; i + len <= stones.size(); i++) {
                dp[i][len] = INT_MAX;
                for (int j = 1; j < len; j += K - 1) {
                    dp[i][len] = min(dp[i][len], dp[i][j] + dp[i + j][len - j]);
                }
                if((len - 1) % (K - 1) == 0) {
                    dp[i][len] += sum[i + len] - sum[i];
                }
            }
        }
        return dp[0][stones.size()];
    }
};
