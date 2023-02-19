class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int result = INT_MAX;
        for (int i = 0, j = nums.size() - 3; i <= 2; i++, j++) {
            result = min(result, nums[j] - nums[i]);
        }
        return result;
    }
};
