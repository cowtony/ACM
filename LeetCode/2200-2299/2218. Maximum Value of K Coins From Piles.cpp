class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // Prefix sum to save some computation for later.
        for (auto& pile : piles) {
            for (int i = 1; i < pile.size(); ++i) {
                pile[i] += pile[i - 1];
            }
        }

        vector<int> dp(k + 1, 0);
        for (const auto& pile : piles) {
            for (int kk = k; kk > 0; --kk) {  // This has to be reverse so that larger `kk` won't be affected by smaller.
                for (int j = 0; j < pile.size() && j < kk; j++) {
                    dp[kk] = max(dp[kk], dp[kk - (j + 1)] + pile[j]);
                }
            }
        }
        return dp[k];
    }
};
