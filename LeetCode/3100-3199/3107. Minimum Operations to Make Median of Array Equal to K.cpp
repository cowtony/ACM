class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long result = 0;
        int idx = nums.size() / 2;
        
        for (int i = 0; i <= idx; i++) {
            result += max(0, nums[i] - k);
        }
        for (int i = idx; i < nums.size(); i++) {
            result += max(0, k - nums[i]);
        }
            
        return result;
    }
};
