class Solution {
public:
    int getMaximumGenerated(int n) {
        // 0 1 2 3 4 5 6 7 8 9 10 11
        // 0 1 1 2 1 3 2 3 1 4 3  5
        // 0 1 1 2 2 3 3 3 3 4 4  5
        if (n == 0) {
            return 0;
        }
        int result = 1;
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                nums[i] = nums[i / 2];
            } else {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }
            result = max(result, nums[i]);
        }
        return result;
    }
};
