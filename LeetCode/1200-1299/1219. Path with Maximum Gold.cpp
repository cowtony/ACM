class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                max_gold = max(max_gold, dfs(grid, r, c));
            }
        }
        return max_gold;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) {
            return 0;
        }

        static const vector<int> kMove = {0, 1, 0, -1, 0};
        int max_gold = 0;
        int temp_gold = grid[r][c];
        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int rr = r + kMove[i];
            int cc = c + kMove[i + 1];
            if (rr < 0 || rr >= grid.size() || cc < 0 || cc >= grid[0].size()) {
                continue;
            }
            max_gold = max(max_gold, dfs(grid, rr, cc));
        }
        grid[r][c] = temp_gold;

        return grid[r][c] + max_gold;
    }
};
