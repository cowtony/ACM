class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            setTo(grid, r, 0);
            setTo(grid, r, grid[0].size() - 1);
        }
        for (int c = 0; c < grid[0].size(); c++) {
            setTo(grid, 0, c);
            setTo(grid, grid.size() - 1, c);
        }
        
        int count = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    count++;
                    setTo(grid, r, c);
                }
            }
        }
        return count;
    }
    
    const vector<int> kX{0, 0, 1, -1};
    const vector<int> kY{1, -1, 0, 0};
    void setTo(vector<vector<int>>& grid, int row, int col, int val = 1) {
        if (row < 0 or row >= grid.size() or col < 0 or col >= grid[0].size()) {
            return;
        }
        if (grid[row][col] == val) {
            return;
        }
        grid[row][col] = val;
        for (int i = 0; i < 4; i++) {
            setTo(grid, row + kX.at(i), col + kY.at(i), val);
        }
    }
};
