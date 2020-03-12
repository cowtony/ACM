class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.back().back() == 1 or obstacleGrid.front().front() == 1) {
            return 0;
        }
        
        vector<vector<long>> dp(obstacleGrid.size(), vector<long>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (j > 0 and obstacleGrid[i][j - 1] == 0) {
                    dp[i][j] += dp[i][j - 1];
                }
                if (i > 0 and obstacleGrid[i - 1][j] == 0) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
