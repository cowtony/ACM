// LeetCode 209: https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        if (nums.empty()) {
            return -1;
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
        return min_len == INT_MAX? -1 : min_len;
    }
};
