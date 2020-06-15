class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int kCol = grid[0].size();
        vector<vector<int>> pre(kCol, vector<int>(kCol, INT_MIN));
        pre[0][kCol - 1] = grid[0][0] + grid[0][kCol - 1];
        
        for (int r = 1; r < grid.size(); r++) {
            vector<vector<int>> dp(kCol, vector<int>(kCol, 0));
            // For each i, j combinition:
            for (int i = 0; i < kCol; i++) {
                for (int j = 0; j < kCol; j++) {
                    dp[i][j] = grid[r][i] + grid[r][j];
                    if (i == j) {
                        dp[i][j] -= grid[r][i];
                    }
                    int max_pre = INT_MIN;
                    // For each possible previous combinition:
                    for (int ii = max(i - 1, 0); ii <= i + 1 and ii < kCol; ii++) {
                        for (int jj = max(j - 1, 0); jj <= j + 1 and jj < kCol; jj++) {
                            max_pre = max(max_pre, pre[ii][jj]);
                        }
                    }
                    dp[i][j] += max_pre;
                }
            }
            pre = dp;
        }
        
        int res = INT_MIN;
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res = max(res, pre[i][j]);
            }
        }
        return res;
    }
};
