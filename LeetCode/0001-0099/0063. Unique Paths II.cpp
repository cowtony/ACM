class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long>> dp(obstacleGrid.size() + 1, vector<long>(obstacleGrid[0].size() + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= obstacleGrid.size(); i++) {
            for (int j = 1; j <= obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i - 1][j - 1] == 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};
