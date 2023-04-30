class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int result = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] > 0) {
                    result = max(result, bfs(grid, r, c));
                }
            }
        }
        return result;
    }
    
    int bfs(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        int fish = grid[row][col];
        grid[row][col] = 0;
        
        while (!q.empty()) {
            auto [rr, cc] = q.front();
            q.pop();
            
            static const vector<int> kMove = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; ++i) {
                int r = rr + kMove[i];
                int c = cc + kMove[i + 1];
                if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
                    continue;
                }
                if (grid[r][c] > 0) {
                    fish += grid[r][c];
                    grid[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        return fish;
    }
};
