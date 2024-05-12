class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (r < grid.size() - 1 && grid[r][c] != grid[r + 1][c]) {
                    return false;
                }
                if (c > 0 && grid[r][c] == grid[r][c - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
