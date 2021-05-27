class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        
        vector<int> sums;
        sums.reserve(nums.size() * (nums.size() + 1) / 2);
        for (int len = 1; len <= nums.size(); len++) {
            for (int i = len; i <= nums.size(); i++) {
                sums.push_back(prefix_sum[i] - prefix_sum[i - len]);
            }
        }
        sort(sums.begin(), sums.end());
        int res = 0;
        for (int i = left - 1; i < right; i++) {
            res += sums[i];
        }
        return res;
    }
};
