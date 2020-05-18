class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    bfs(grid, r, c);
                }
            }
        }
        
        int min_step = INT_MIN;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] < 0) {
                    min_step = max(min_step, grid[r][c]);
                }
            }
        }
        return min_step == INT_MIN? -1 : -min_step;
    }
    
    const vector<int> kX = {0, 0, 1, -1};
    const vector<int> kY = {1, -1, 0, 0};
    void bfs(vector<vector<int>> &grid, int row, int col) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        visited[row][col] = true;
        q.push(make_pair(-1, -1));
        int layer = 0;
        while (!q.empty()) {
            auto coor = q.front();
            q.pop();
            
            if (coor.first == -1) {
                layer++;
                q.push(make_pair(-1, -1));
                if (q.front().first == -1) {
                    break;
                }
                continue;
            }
            
            grid[coor.first][coor.second] -= layer;
            
            for (int i = 0; i < 4; i++) {
                int r = coor.first + kX.at(i);
                int c = coor.second + kY.at(i);
                
                if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size()) {
                    continue;
                }
                if (!visited[r][c] and grid[r][c] <= 0) {
                    visited[r][c] = true;
                    q.push(make_pair(r, c));
                }
            }
        }
        // Change all unvisited empty cell to wall, this cannot be reached by this house.
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                // cout << grid[r][c] << ' ';
                if (grid[r][c] <= 0 and !visited[r][c]) {
                    grid[r][c] = 2;
                }
            }
            // cout << endl;
        }
    }
};
