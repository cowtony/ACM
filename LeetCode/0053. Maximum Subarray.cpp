class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int DP = 0;
        int ret = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            DP = max(nums[i], DP + nums[i]);
            ret = max(ret, DP);
        }
        return ret;
    }
};
