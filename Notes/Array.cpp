// 1D Prefx Sum.
vector<int> prefix_sum(nums.size() + 1, 0);
for (int i = 0; i < nums.size(); i++) {
    prefix_sum[i + 1] = prefix_sum[i] + nums[i];
}

// 2D Prefx Sum.
vector<vector<int>> prefixSum(vector<vector<int>>& matrix) {
    int R = matrix.size();
    int C = matrix.empty()? 0 : matrix[0].size();
    auto prefix_sum = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            prefix_sum[r + 1][c + 1] = matrix[r][c] 
                                     + prefix_sum[r][c + 1]
                                     + prefix_sum[r + 1][c]
                                     - prefix_sum[r][c];
        }
    }
    return prefix_sum;
}

// Print
void printMatrix(const vector<vector<int>>& matrix) {
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix.at(r).size(); c++) {
            cout << matrix.at(r).at(c) << ' ';
        }
        cout << endl;
    }
}
auto printMatrix = [](const vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.at(i).size(); j++) {
            cout << A.at(i).at(j) << ' ';
        }
        cout << endl;
    }
};
