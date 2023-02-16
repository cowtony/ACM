class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), INT_MIN));
        dp[0][0] = grid[0][0];
        for (int step = 1; step <= grid.size() + grid[0].size() - 2; step++) {
            vector<vector<int>> temp_dp(grid.size(), vector<int>(grid.size(), INT_MIN));
            int r1 = min(step, int(grid.size()) - 1);
            int c1 = max(0, step - int(grid.size()) + 1);
            for (; r1 >= 0 && c1 < grid.size(); r1--, c1++) {
                if (grid[r1][c1] == -1) {
                    continue;
                }
                int r2 = min(step, int(grid.size()) - 1);
                int c2 = max(0, step - int(grid.size()) + 1);
                for (; r2 >= 0 && c2 < grid.size(); r2--, c2++) {
                    if (grid[r2][c2] == -1 || r2 < r1) {
                        continue;
                    }
                    int cherry = c1 == c2 ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
                    temp_dp[c1][c2] = max(temp_dp[c1][c2], cherry + dp[c1][c2]);
                    if(c1 > 0)
                        temp_dp[c1][c2] = max(temp_dp[c1][c2], cherry + dp[c1 - 1][c2]);
                    if(c2 > 0)
                        temp_dp[c1][c2] = max(temp_dp[c1][c2], cherry + dp[c1][c2 - 1]);
                    if(c1 > 0 && c2 > 0)
                        temp_dp[c1][c2] = max(temp_dp[c1][c2], cherry + dp[c1 - 1][c2 - 1]);
                }
            }
            dp = temp_dp;
        }
        return max(0, dp[grid.size() - 1][grid.size() - 1]);
    }
};
