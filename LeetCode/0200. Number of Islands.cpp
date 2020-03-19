// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == '1')
                {
                    count++;
                    setZero(grid, row, col);
                }
                    
            }
        }
        return count;
    }
    
    void setZero(vector<vector<char>>& grid, const int &row, const int &col) {
        if (grid[row][col] == '1')
        {
            grid[row][col] = '0';
            if (row + 1 < grid.size())
                setZero(grid, row + 1, col);
            if (col + 1 < grid[0].size())
                setZero(grid, row, col + 1);
            if (row - 1 >= 0)
                setZero(grid, row - 1, col);
            if (col - 1 >= 0)
                setZero(grid, row, col - 1);
        }
    }
};
