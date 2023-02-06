class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        // Clear one bottom boundary path.
        if (!dfs(grid, 0, 0)) {
            return true;  // No pass at all.
        }
        return !dfs(grid, 0, 0);  // See if there is another path.
    }
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return false;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }
        if (i + j > 0) {
            grid[i][j] = 0;  // clear this block. (Exclude start point and end point)
        }
        return dfs(grid, i + 1, j) || dfs(grid, i, j + 1);
    }

    // DP approach, this is reaching the int32 limit so have to use int64.
    bool isPossibleToCutPath2(vector<vector<int>>& grid) {
        // Find the number of ways to reach [i][j] from [0][0].
        vector<vector<uint64_t>> A(grid.size(), vector<uint64_t>(grid[0].size(), 0));
        A[0][0] = 1;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    if (r > 0) {
                        A[r][c] += A[r - 1][c];
                    }
                    if (c > 0) {
                        A[r][c] += A[r][c - 1];
                    }
                }
            }
        }
        // Find the number of ways to reach [i][j] from [m][n].
        vector<vector<uint64_t>> B(grid.size(), vector<uint64_t>(grid[0].size(), 0));
        B[grid.size() - 1][grid[0].size() - 1] = 1; 
        for (int r = grid.size() - 1; r >= 0; r--) {
            for (int c = grid[0].size() - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    if (r < grid.size() - 1) {
                        B[r][c] += B[r + 1][c];
                    }
                    if (c < grid[0].size() - 1) {
                        B[r][c] += B[r][c + 1];
                    }
                }
            }
        }
                
        uint64_t m = B[0][0];
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (r + c > 0 && r + c < grid.size() + grid[0].size() - 2) {
                    if (A[r][c] * B[r][c] == B[0][0]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
