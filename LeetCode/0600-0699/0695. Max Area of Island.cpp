class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    area = max(area, islandArea(grid, i, j));
                }
            }
        }
        return area;
    }
private:
    int islandArea(vector<vector<int>>& grid, int row, int col) {
        if (grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        int area = 1;
        
        static const vector<int> kMove = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int r = row + kMove[i];
            int c = col + kMove[i + 1];
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
                area += islandArea(grid, r, c);
            }
        }
        return area;
    }
};
