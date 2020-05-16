class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        int max_sum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            max_sum =max(max_sum, sum);
        }
        return max_sum;
    }
};
