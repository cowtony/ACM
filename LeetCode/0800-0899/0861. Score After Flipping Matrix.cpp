class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int kRow = grid.size(), kCol = grid[0].size();
        int power = 1 << (kCol - 1);
        int result = power * kRow;
        power >>= 1;
        for (int c = 1; c < kCol; c++, power >>= 1) {
            int count = 0;
            for (int r = 0; r < kRow; r++) {
                count += grid[r][c] ^ grid[r][0]; // Flip row r if grid[r][0] == 0
            }
            count = max(count, kRow - count); // Flip column c if needed.
            result += power * count;
        }
        return result;
    }
};
