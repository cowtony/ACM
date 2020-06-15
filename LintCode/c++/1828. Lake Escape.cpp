class Solution {
public:
    /**
     * @param side_length: the length of a side of the lake (it's a square)
     * @param lake_grid: a 2D matrix representing the lake 0= ice, 1= snowbank, -1= hole 
     * @param albert_row: row of Albert's snowbank
     * @param albert_column: column of Albert's snowbank 
     * @param kuna_row: row of Kuna's snowbank 
     * @param kuna_column: column of Kuna's snowbank
     * @return: a bool - whether Albert can escape
     */
    bool lakeEscape(int side_length, vector<vector<int>> &lake_grid, int albert_row, int albert_column, int kuna_row, int kuna_column) {
        
        auto hash = [&](int r, int c){ return r * lake_grid[0].size() + c; };
        
        struct Node {
            int row;
            int col;
            bool touched_pup = false;
        };
        unordered_set<int> visited;
        queue<Node> q;
        q.push({albert_row, albert_column});
        visited.insert(hash(albert_row, albert_column));
        const vector<int> kX = {0, 0, 1, -1};
        const vector<int> kY = {1, -1, 0, 0};
        
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                for (int k = 1; ; k++) {
                    int r = n.row + kX.at(i) * k;
                    int c = n.col + kY.at(i) * k;
                    if (r == kuna_row and c == kuna_column) {
                        n.touched_pup = true;
                    }
                    if (r < 0 or r >= lake_grid.size() or c < 0 or c >= lake_grid[0].size()) {
                        if (n.touched_pup) {
                            return true;
                        }
                        break;
                    }
                    if (lake_grid[r][c] == 0) {
                        continue;
                    }
                    
                    if (lake_grid[r][c] == -1) {
                        break;
                    }
                    if (visited.find(hash(r, c)) != visited.end()) {
                        break;
                    }
                    if (lake_grid[r][c] == 1) {
                        
                        q.push({r, c, n.touched_pup});
                        visited.insert(hash(r, c));
                    }
                }
                
            }
        }
        return false;
    }
};
