class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int flip_count = 0;
        int min_diff = INT_MAX;
        long long sum_val = 0;
        for (int num : nums) {
            if ((num ^ k) > num) {
                flip_count++;
            }
            sum_val += max(num, num ^ k);
            min_diff = min(min_diff, abs((num ^ k) - num));
        }

        if (flip_count % 2 == 1) {
            sum_val -= min_diff;
        }
        return sum_val;
    }
};
