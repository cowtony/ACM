class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increase = 1, decrease = 1;
        int increase_idx = 0, decrease_idx = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                increase = max(increase, i - increase_idx + 1);
            } else {
                increase_idx = i;
            }
            
            if (nums[i] < nums[i - 1]) {
                decrease = max(decrease, i - decrease_idx + 1);
            } else {
                decrease_idx = i;
            }
        }
        
        return max(increase, decrease);
    }
};
