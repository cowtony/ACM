class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> result(grid.size() - 2, vector<int>(grid.size() - 2));

        for (int r = 1; r < grid.size() - 1; r++) {
            for (int c = 1; c < grid[0].size() - 1; c++) {
                result[r - 1][c - 1] = max({grid[r - 1][c - 1], grid[r][c - 1], grid[r + 1][c - 1],
                                            grid[r - 1][c],     grid[r][c],     grid[r + 1][c],
                                            grid[r - 1][c + 1], grid[r][c + 1], grid[r + 1][c + 1]});
            }
        }
        return result;
    }
};
