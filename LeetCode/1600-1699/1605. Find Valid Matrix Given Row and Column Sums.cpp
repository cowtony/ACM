class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int kRow = rowSum.size(), kCol = colSum.size();
        vector<vector<int>> result(kRow, vector<int>(kCol, 0));
        for (int r = 0; r < kRow; ++r) {
            for (int c = 0; c < kCol; ++c) {
                result[r][c] = min(rowSum[r], colSum[c]);
                rowSum[r] -= result[r][c];
                colSum[c] -= result[r][c];
                if (rowSum[r] == 0) {
                    break;
                }
            }
        }
        return result;
    }
};
