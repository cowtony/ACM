class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<int> prefix_sum(stones.size() + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + stones[i];
        }
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));
        
        for (int len = 1; len < stones.size(); len++) {
            for (int i = 0; i + len < stones.size(); i++) {
                dp[i][i + len] = max(prefix_sum[i + len + 1] - prefix_sum[i + 1] - dp[i + 1][i + len], 
                                     prefix_sum[i + len] - prefix_sum[i] - dp[i][i + len - 1]);
            }
        }
        
        return dp[0][stones.size() - 1];
    }
};
