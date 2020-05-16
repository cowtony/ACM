class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the number of distinct islands
     */
    int numDistinctIslands2(vector<vector<int>> &grid) {
        unordered_set<string> islands;
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    vector<int> row_sum(grid.size(), 0);
                    vector<int> col_sum(grid[0].size(), 0);
                    findIsland(grid, r, c, row_sum, col_sum);
                    string s = hash(row_sum, col_sum);
                    cout << s << endl;
                    islands.insert(s);
                }
            }
        }
        
        return islands.size();
    }
    
private:
    const vector<int> kX = {0, 0, 1, -1};
    const vector<int> kY = {1, -1, 0, 0};
    void findIsland(vector<vector<int>>& grid, int r, int c, vector<int>& row_sum, vector<int>& col_sum) {
        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            row_sum[r]++;
            col_sum[c]++;
        } else {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int rr = r + kX.at(i);
            int cc = c + kY.at(i);
            
            if (rr < 0 or rr >= grid.size() or cc < 0 or cc >= grid[0].size()) {
                continue;
            }
            findIsland(grid, rr, cc, row_sum, col_sum);
        }
    }
    
    string hash(vector<int>& row_sum, vector<int>& col_sum) {
        while (row_sum.front() == 0) {
            row_sum.erase(row_sum.begin());
        }
        while (row_sum.back() == 0) {
            row_sum.pop_back();
        }
        while (col_sum.front() == 0) {
            col_sum.erase(col_sum.begin());
        }
        while (col_sum.back() == 0) {
            col_sum.pop_back();
        }
        string row;
        for (int num : row_sum) {
            row += char(num + '1');
        }
        row = reverseSmaller(row);

        string col;
        for (int num : col_sum) {
            col += char(num + '1');
        }
        col = reverseSmaller(col);
        
        if (row < col) {
            return row + '0' + col;
        } else {
            return col + '0' + row;
        }
    }
    
    string reverseSmaller(string a) {
        string rev = a;
        reverse(rev.begin(), rev.end());
        return min(a, rev);
    }
};
