class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        vector<vector<int>> rows(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            int enemy = 0;
            int pre_j = -1;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 'E') {
                    enemy++;
                } else if (grid[i][j] == 'W') {
                    for (int k = pre_j + 1; k < j; k++) {
                        rows[i][k] = enemy;
                    }
                    pre_j = j;
                    enemy = 0;
                }
            }
            for (int k = pre_j + 1; k < grid[0].size(); k++) {
                rows[i][k] = enemy;
            }
        }
        
        vector<vector<int>> cols(grid.size(), vector<int>(grid[0].size(), 0));
        for (int j = 0; j < grid[0].size(); j++) {
            int enemy = 0;
            int pre_i = -1;
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][j] == 'E') {
                    enemy++;
                } else if (grid[i][j] == 'W') {
                    for (int k = pre_i + 1; k < i; k++) {
                        cols[k][j] = enemy;
                    }
                    pre_i = i;
                    enemy = 0;
                }
            }
            for (int k = pre_i + 1; k < grid.size(); k++) {
                cols[k][j] = enemy;
            }
        }
        
        int max_enemy = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0') {
                    max_enemy = max(max_enemy, rows[i][j] + cols[i][j]);
                }
            }
        }
        return max_enemy;
    }
};
