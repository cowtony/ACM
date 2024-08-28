class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[i].size(); j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    bool dfs(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0) {
            return true;
        }
        bool result = true;
        grid2[i][j] = 0;
        result &= dfs(grid1, grid2, i - 1, j);
        result &= dfs(grid1, grid2, i + 1, j);
        result &= dfs(grid1, grid2, i, j - 1);
        result &= dfs(grid1, grid2, i, j + 1);
        if (grid1[i][j] == 0) {
            result = false;
        }
        return result;
    }
};
