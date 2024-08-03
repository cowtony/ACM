class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int count_1 = 0;
        for (const auto& row : grid) {
            for (int i = 0, j = row.size() - 1; i < j; i++, j--) {
                if (row[i] != row[j]) {
                    count_1++;
                }
            }
        }
        int count_2 = 0;
        for (int c = 0; c < grid[0].size(); c++) {
            for (int i = 0, j = grid.size() - 1; i < j; i++, j--) {
                if (grid[i][c] != grid[j][c]) {
                    count_2++;
                }
            }
        }
        return min(count_1, count_2);
    }
};
