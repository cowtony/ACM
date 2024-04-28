class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> count_col(grid[0].size(), 0);
        vector<int> count_row(grid.size(), 0);
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                count_col[c] += grid[r][c];
                count_row[r] += grid[r][c];
            }
        }
        
        long long count = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    count += (long long)(count_col[c] - 1) * (count_row[r] - 1);
                }
                
            }
        }
        return count;
    }
};
