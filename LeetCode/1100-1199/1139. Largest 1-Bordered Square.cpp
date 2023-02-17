class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        // Store the number of continious 1s.
        vector<vector<int>> dp_row(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> dp_col(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dp_row[i][j] = (j > 0? dp_row[i][j - 1] : 0) + 1;
                    dp_col[i][j] = (i > 0? dp_col[i - 1][j] : 0) + 1;
                } else {
                    dp_row[i][j] = 0;
                    dp_col[i][j] = 0;
                }
            }
        }

        for (int len = min(grid.size(), grid[0].size()); len > 0; len--) {
            for (int i = 0; i + len - 1 < grid.size(); i++) {
                for (int j = 0; j + len - 1 < grid[0].size(); j++) {
                    if (dp_row[i][j + len - 1] >= len &&
                        dp_row[i + len - 1][j + len - 1] >= len &&
                        dp_col[i + len - 1][j] >= len &&
                        dp_col[i + len - 1][j + len - 1] >= len) {
                        return len * len;
                    }
                }
            }
        }
        return 0;
    }
};
