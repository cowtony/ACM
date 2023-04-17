class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> result(grid[0].size(), 0);
        for (int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                result[c] = max(result[c], int(to_string(grid[r][c]).length()));
            }
        }
        return result;
    }
};
