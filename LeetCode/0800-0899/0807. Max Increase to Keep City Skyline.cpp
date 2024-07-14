class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int N = grid.size();
        vector<int> horizontal(N, 0);
        vector<int> vertical(N, 0);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                horizontal[r] = max(horizontal[r], grid[r][c]);
                vertical[c] = max(vertical[c], grid[r][c]);
            }
        }

        int result = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                result += min(horizontal[r], vertical[c]) - grid[r][c];
            }
        }

        return result;
    }
};
