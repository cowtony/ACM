class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        vector<int> dp(grid[0].size() + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j];
            }
        }
        return dp[grid[0].size()];
    }
};
