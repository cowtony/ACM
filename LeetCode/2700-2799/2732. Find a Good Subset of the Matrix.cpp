class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        // The answer only contains 1 row.
        for (int row = 0; row < grid.size(); row++) {
            bool all_zero = true;
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) {
                return {row};
            }
        }

        // The answer only contains 2 rows.
        for (int r1 = 0; r1 < grid.size(); r1++) {
            for (int r2 = r1 + 1; r2 < grid.size(); r2++) {
                bool possible = true;
                for (int col = 0; col < grid[0].size(); col++) {
                    if (grid[r1][col] + grid[r2][col] == 2) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    return {r1, r2};
                }
            }
        }

        return {};
    }
};
