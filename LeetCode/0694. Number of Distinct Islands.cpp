class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    vector<int> row_sum(grid.size(), 0);
                    vector<int> col_sum(grid[0].size(), 0);
                    string s;
                    R = r;
                    C = c;
                    findIsland(grid, r, c, s);
                    
                    islands.insert(s);
                }
            }
        }
        
        return islands.size();
    }
    
private:
    const vector<int> kX = {0, 0, 1, -1};
    const vector<int> kY = {1, -1, 0, 0};
    int R, C;
    void findIsland(vector<vector<int>>& grid, int r, int c, string& hash) {
        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            hash += '0' + r - R;
            hash += '0' + c - C;
        } else {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int rr = r + kX.at(i);
            int cc = c + kY.at(i);
            
            if (rr < 0 or rr >= grid.size() or cc < 0 or cc >= grid[0].size()) {
                continue;
            }
            findIsland(grid, rr, cc, hash);
        }
    }
};
