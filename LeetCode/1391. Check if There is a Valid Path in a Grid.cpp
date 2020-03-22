class Solution {
public:
    vector<unordered_set<int>> right = {{}, {1, 3, 5}, {}, {}, {1, 3, 5}, {}, {1, 3, 5}};
    vector<unordered_set<int>> left  = {{}, {1, 4, 6}, {}, {1, 4, 6}, {}, {1, 4, 6}, {}};
    vector<unordered_set<int>> up    = {{}, {}, {2, 3, 4}, {}, {}, {2, 3, 4}, {2, 3, 4}};
    vector<unordered_set<int>> down  = {{}, {}, {2, 5, 6}, {2, 5, 6}, {2, 5, 6}, {}, {}};
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int width = grid[0].size();
        
        if (grid[0][0] == 4) {
            grid[0][0] = -grid[0][0];
            return run(grid, 0, 1) or run(grid, 1, 0);
        } else {
            return run(grid, 0, 0);
        }
    }
    
    bool run(vector<vector<int>> grid, int i, int j) {
        int width = grid[0].size();
        
        while (true) {
            if (i == grid.size() - 1 and j == width - 1) {
                return true;
            }
            grid[i][j] = -grid[i][j]; // visited.
            if (j + 1 < width and grid[i][j + 1] > 0 and right[-grid[i][j]].find(grid[i][j + 1]) != right[-grid[i][j]].end()) {
                j++;
                continue;
            } else if (j > 0 and grid[i][j - 1] > 0 and left[-grid[i][j]].find(grid[i][j - 1]) != left[-grid[i][j]].end()) {
                j--;
                continue;
            } else if (i + 1 < grid.size() and grid[i + 1][j] > 0 and down[-grid[i][j]].find(grid[i + 1][j]) != down[-grid[i][j]].end()) {
                i++;
                continue;
            } else if (i > 0 and grid[i - 1][j] > 0 and up[-grid[i][j]].find(grid[i - 1][j]) != up[-grid[i][j]].end()) {
                i--;
                continue;
            }
            return false;
        }
    }
};
