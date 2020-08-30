class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int count_1 = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    count_1++;
                }
            }
        }
        
        if (!oneIsland(grid, count_1)) {
            return 0;
        }
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    if (!oneIsland(grid, count_1 - 1)) {
                        return 1;
                    }
                    grid[row][col] = 1;
                }
            }
        }
        
        return 2;
    }
    
    bool oneIsland(vector<vector<int>> grid, int area) {
        if (area == 0) {
            return false;
        }
        static const vector<int> kMove = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        for (int row = 0; row < grid.size() and q.empty(); row++) {
            for (int col = 0; col < grid[0].size() and q.empty(); col++) {
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    q.push({row, col});
                    area--;
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int rr = r + kMove[i];
                int cc = c + kMove[i + 1];

                if (rr < 0 or rr >= grid.size() or cc < 0 or cc >= grid[0].size()) {
                    continue;
                }
                if (grid[rr][cc] == 1) {
                    grid[rr][cc] = 0;
                    area--;
                    q.push({rr, cc});
                }
            }
        }
        return area == 0;
    }
};
