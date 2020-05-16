// LeetCode 643: https://leetcode.com/problems/maximum-average-subarray-i/
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        int sum = INT_MIN;
        for (int i = k; i < nums.size(); i++) {
            sum = max(sum, nums[i] - nums[i - k]);
        }
        return sum / double(k);
    }
};
