class Solution {
public:
    /**
     * @param grid: the input matrix
     * @return: the new matrix
     */
    vector<vector<int>> shortestPath(vector<vector<int>> &grid) {
        vector<int> x = {0, 0, 1, -1, 0, 0};
        vector<int> y = {0, 0, 0, 0, 1, -1};
        
        vector<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push_back({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            vector<pair<int, int>> next_q;
            
            for (int k = 2; k <= 5; k++) {
                for (auto p : q) {
                    int ii = p.first + x[k];
                    int jj = p.second + y[k];
                    
                    if (ii < 0 or ii >= grid.size()) {
                        continue;
                    }
                    if (jj < 0 or jj >= grid[0].size()) {
                        continue;
                    }
                    if (grid[ii][jj] == -1) {
                        continue;
                    }
                    if (grid[ii][jj] == 0) {
                        grid[ii][jj] = k;
                        next_q.push_back({ii, jj});
                    }
                }
            }
            q = next_q;
        }
        
        return grid;
    }
};
