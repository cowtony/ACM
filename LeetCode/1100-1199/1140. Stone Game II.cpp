class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, -1));
        vector<int> prefix_sum(piles.size() + 1, 0);
        for (int i = 0; i < piles.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + piles[i];
        }

        return dfs(piles, prefix_sum, dp, 0, 1);
    }

    int dfs(const vector<int>& piles, const vector<int>& sums, 
            vector<vector<int>>& dp, int i, int m) {
        if (dp[i][m] != -1) {
            return dp[i][m];
        }
        int max_score = 0;
        for (int x = 1; x <= 2 * m && i + x <= piles.size(); x++) {
            max_score = max(max_score, sums.back() - sums[i] - dfs(piles, sums, dp, i + x, max(x, m)));
        }
        return dp[i][m] = max_score;
    }
};
