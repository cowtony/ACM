class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int r = 1; r < 3; r++) {
            for (int c = 1; c < 3; c++) {
                int count = (grid[r][c] == 'B'? 1:0) + (grid[r - 1][c] == 'B'? 1:0) + (grid[r][c - 1] == 'B'? 1:0) + (grid[r - 1][c - 1] == 'B'? 1:0);
                if (count != 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
