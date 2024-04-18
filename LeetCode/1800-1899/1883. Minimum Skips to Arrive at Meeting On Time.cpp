class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        // dp[i][j] is the time used for first i pathes and j skips.
        vector<vector<long>> dp(dist.size() + 1, vector<long>(dist.size() + 1, LONG_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < dist.size(); ++i) {
            for (int j = 0; j <= i + 1; ++j) {
                if (j < i + 1) {
                    dp[i + 1][j] = min(dp[i + 1][j], ((dp[i][j] + dist[i] - 1) / speed + 1) * speed);
                }
                if (j > 0) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - 1] + dist[i]);
                }
            }
        }
        for (int j = 0; j <= dist.size(); ++j) {
            if (dp[dist.size()][j] <= (long)hoursBefore * speed) {
                return j;
            }
        }
        return -1;
    }
};
