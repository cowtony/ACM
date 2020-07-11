class Solution {
public:
    /**
     * @param p: The time you choose to do part of the problem.
     * @param part: The points you choose to do part of the problem.
     * @param f: The time you choose to do the whole problem.
     * @param full: The points you choose to do the whole problem.
     * @return: Return the maximum number of points you can get.
     */
    int exam(vector<int> &p, vector<int> &part, vector<int> &f, vector<int> &full) {
        vector<vector<int>> dp(p.size() + 1, vector<int>(120 + 1, 0));
        
        int res = 0;
        for (int i = 1; i <= p.size(); i++) {
            for (int t = 0; t <= 120; t++) {
                dp[i][t] = dp[i - 1][t];
                if (t >= p[i - 1]) {
                    dp[i][t] = max(dp[i][t], dp[i - 1][t - p[i - 1]] + part[i - 1]);
                }
                if (t >= f[i - 1]) {
                    dp[i][t] = max(dp[i][t], dp[i - 1][t - f[i - 1]] + full[i - 1]);
                }
                res = max(res, dp[i][t]);
            }
        }
        return res;
    }
};
