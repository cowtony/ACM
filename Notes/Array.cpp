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

// Next Premutation
void next_permutation(vector<int>& nums) {
    int i;
    for (i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }

    // Exclude the case all numbers are decending and i = -1;
    if (i >= 0) {
        int j;
        for (j = i + 1; j < nums.size() - 1; j++) {
            if (nums[i] >= nums[j + 1]) {
                break;
            }
        }
        // Swap the two key values.
        swap(nums[i], nums[j]);
    }

    // Reverse the rest line.
    reverse(nums.begin() + i + 1, nums.end());
}
