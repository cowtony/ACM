class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        prefix_row = vector<vector<int>>(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        prefix_col = vector<vector<int>>(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                prefix_row[r][c + 1] = prefix_row[r][c] + grid[r][c];
                prefix_col[r + 1][c] = prefix_col[r][c] + grid[r][c];
            }
        }

        for (int size = min(grid.size(), grid[0].size()); size > 1; size--) {
            for (int row = 0; row <= grid.size() - size; row++) {
                for (int col = 0; col <= grid[0].size() - size; col++) {
                    if (isMagicSquare(grid, row, col, size)) {
                        return size;
                    }
                }
            }
        }
        return 1;
    }

    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col, int size) {
        int sum = prefix_row[row][col + size] - prefix_row[row][col];
        int left = 0, right = 0;
        for (int i = 0; i < size; i++) {
            if (prefix_row[row + i][col + size] - prefix_row[row + i][col] != sum) {
                return false;
            }
            if (prefix_col[row + size][col + i] - prefix_col[row][col + i] != sum) {
                return false;
            }
            left += grid[row + i][col + i];
            right += grid[row + i][col + size - 1 - i];
        }
        return sum == left && sum == right;
    }

    vector<vector<int>> prefix_row;
    vector<vector<int>> prefix_col;
};