class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        for (int r = 1; r < grid.size() - 1; r++) {
            for (int c = 1; c < grid[r].size() - 1; c++) {
                if (isMagicSquare(grid, r, c)) {
                    result++;
                }
            }
        }
        return result;
    }

    // Input square center's pos.
    bool isMagicSquare(const vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] != 5) {
            return false;
        }
    
        unordered_set<int> visited;
        for (int i = r - 1; i <= r + 1; i++) {
            for (int j = c - 1; j <= c + 1; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) {
                    return false;
                }
                visited.insert(grid[i][j]);
            }
        }
        if (visited.size() != 9) {
            return false;
        }

        return grid[r - 1][c - 1] + grid[r + 1][c + 1] == 10 
            && grid[r - 1][c] + grid[r + 1][c] == 10
            && grid[r - 1][c - 1] + grid[r - 1][c] + grid[r - 1][c + 1] == 15
            && grid[r - 1][c - 1] + grid[r][c - 1] + grid[r + 1][c - 1] == 15;
    }
};
