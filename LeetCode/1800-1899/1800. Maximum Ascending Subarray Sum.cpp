class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                sum = 0;
            }
            sum += nums[i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
