class Solution {
public:
    /**
     * @param matrix: an integer array of n * m matrix
     * @param k: An integer
     * @return: the maximum number
     */
    int maxSlidingMatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.size() < k or matrix[0].size() < k) {
            return 0;
        }
        
        vector<vector<int>> sums(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
            }
        }
        
        int ans = INT_MIN;
        for (int i = k; i <= matrix.size(); i++) {
            for (int j = k; j <= matrix[0].size(); j++) {
                ans = max(ans, sums[i][j] - sums[i - k][j] - sums[i][j - k] + sums[i - k][j - k]);
            }
        }
        return ans;
    }
};
