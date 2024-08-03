class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int R = grid.size();
        const int C = grid[0].size();
        
        int count = 0;
        
        int ones = 0;
        if (R % 2 == 1) {
            const int mid_row = R / 2;
            for (int i = 0, j = C - 1; i < j; i++, j--) {
                if (grid[mid_row][i] != grid[mid_row][j]) {
                    count++;
                }
                ones += grid[mid_row][i] + grid[mid_row][j];
            }
        }
        if (C % 2 == 1) {
            const int mid_col = C / 2;
            for (int i = 0, j = R - 1; i < j; i++, j--) {
                if (grid[i][mid_col] != grid[j][mid_col]) {
                    count++;
                }
                ones += grid[i][mid_col] + grid[j][mid_col];
            }
        }
        count = max(count, min(ones % 4, 4 - (ones % 4)));
        
        // Make the very center cell to 0.
        if (R % 2 == 1 && C % 2 == 1 && grid[R / 2][C / 2] == 1) {
            count++;
        }
        
        // Handle the 4 corners:
        for (int ri = 0, rj = R - 1; ri < rj; ri++, rj--) {
            for (int ci = 0, cj = C - 1; ci < cj; ci++, cj--) {
                int ones = grid[ri][ci] + grid[ri][cj] + grid[rj][ci] + grid[rj][cj];
                count += min(ones, 4 - ones);
            }
        }
        
        return count;
    }
};
