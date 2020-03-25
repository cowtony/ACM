// LeetCode 644: https://leetcode.com/problems/maximum-average-subarray-ii/
class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        double low = nums[0], high = nums[0];
        for (double num : nums) {
            low = min(low, num);
            high = max(high, num);
        }
        while (high - low > 1e-6) {
            double mid = (high + low) / 2;
            if (possible(nums, k, mid)) {
                low = mid;
            } else {
                high = mid;
            }
        } 
        return low;
    }
    
    bool possible(vector<int> &nums, int k, double average) {
        vector<double> sumNums(nums.size() + 1);
        sumNums[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sumNums[i + 1] = sumNums[i] + nums[i] - average;
        }
        double preMin = 0;
        for (int i = k; i <= nums.size(); i++) {
            if (sumNums[i] - preMin >= 0) {
                return true;
            }
            preMin = min(preMin, sumNums[i - k + 1]);
        }
        return false;
    }
};
