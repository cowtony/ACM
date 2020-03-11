class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int lo = 0, hi = 0;
        int sum = nums[0];
        int min_len = INT_MAX;
        while (true) {
            if (sum >= s) {
                min_len = min(min_len, hi - lo + 1);
                sum -= nums[lo];
                lo++;
            } else {
                hi++;
                if (hi >= nums.size()) {
                    break;
                }
                sum += nums[hi];
            }
        }
        return min_len == INT_MAX? 0 : min_len;
    }
};
