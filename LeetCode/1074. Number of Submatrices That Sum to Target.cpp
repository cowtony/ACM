class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> sums(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                sums[r + 1][c + 1] = sums[r][c + 1] + sums[r + 1][c] - sums[r][c] + matrix[r][c];
            }
        }
        
        int count = 0;
        for (int r1 = 0; r1 < matrix.size(); r1++) {
            for (int r2 = r1; r2 < matrix.size(); r2++) {
                // Iterate all rows combination.
                unordered_map<int, int> m;
                for (int i = 0; i < sums[0].size(); i++) {
                    int sum = sums[r2 + 1][i] - sums[r1][i];
                    if (m.find(sum - target) != m.end()) {
                        count += m.at(sum - target);
                    }
                    m[sum]++;
                }
            }
        }
        return count;
    }
};
