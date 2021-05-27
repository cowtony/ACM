class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater());
        
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        int sub_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sub_sum += nums[i];
            if (sub_sum > sum / 2) {
                return {nums.begin(), nums.begin() + i + 1};
            }
        }
        return nums;
    }
};
