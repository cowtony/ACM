class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), 0));
        for (int len = 2; len < values.size(); ++len) {
            for (int i = 0, j = len; j < values.size(); ++i, ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + 
                                             dp[k][j] + 
                                             values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][values.size() - 1];
    }
};
