class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0]);
        for (int r = 1; r < grid.size(); r++) {
            auto [min_idx, min_val] = minExclude(dp, -1);
            dp[min_idx] = grid[r][min_idx] + minExclude(dp, min_idx).second;
            for (int c = 0; c < grid[r].size(); c++) {
                if (c != min_idx) {
                    dp[c] = grid[r][c] + min_val;
                }
            }
        }
        return minExclude(dp, -1).second;
    }

    pair<int, int> minExclude(const vector<int>& arr, int exclude_idx) {
        int result = INT_MAX;
        int idx = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (i != exclude_idx && arr[i] < result) {
                result = arr[i];
                idx = i;
            }
        }
        return {idx, result};
    }
};
