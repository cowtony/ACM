class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (row + col == 0) {
                    continue;
                }
                grid[row][col] += min(row > 0? grid[row - 1][col] : INT_MAX, 
                                      col > 0? grid[row][col - 1] : INT_MAX);
            }
        }
        return grid.back().back();
    }
};
