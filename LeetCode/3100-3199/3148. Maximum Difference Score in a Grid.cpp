class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> max_val(grid.size(), vector<int>(grid[0].size(), INT_MIN));
        int result = INT_MIN;
        for (int r = grid.size() - 1; r >= 0; r--) {
            for (int c = grid[0].size() - 1; c >= 0; c--) {
                if (r + 1 < grid.size()) {
                    result = max(result, max_val[r + 1][c] - grid[r][c]);
                    max_val[r][c] = max(max_val[r][c], max_val[r + 1][c]);
                }
                if (c + 1 < grid[0].size()) {
                    result = max(result, max_val[r][c + 1] - grid[r][c]);
                    max_val[r][c] = max(max_val[r][c], max_val[r][c + 1]);
                }
                max_val[r][c] = max(max_val[r][c], grid[r][c]);
            }
        }
        
        return result;
    }
};
