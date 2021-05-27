class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {        
        struct Pos {
            int row, col;
            int pre_r = -1, pre_c = -1;
        };
        
        const vector<int> kMove{0, 1, 0, -1, 0};
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (visited[r][c]) {
                    continue;
                }
                
                queue<Pos> q;
                q.push({r, c});
                visited[r][c] = true;
                while (!q.empty()) {
                    Pos p = q.front();
                    q.pop();
                    
                    for (int i = 0; i < 4; i++) {
                        int r = p.row + kMove[i];
                        int c = p.col + kMove[i + 1];
                        
                        if (r == p.pre_r and c == p.pre_c) {
                            continue;
                        }
                        if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size()) {
                            continue;
                        }
                        if (grid[r][c] != grid[p.row][p.col]) {
                            continue;
                        }
                        
                        if (visited[r][c]) {
                            return true;
                        }
                        q.push({r, c, p.row, p.col});
                        visited[r][c] = true;
                    }
                }
            }
        }
        return false;
    }
};
