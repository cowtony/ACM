class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        
        // Exclude the case all numbers are decending and i = -1;
        if (i >= 0) {
            int j;
            for (j = i + 1; j < nums.size() - 1; j++) {
                if (nums[i] >= nums[j + 1]) {
                    break;
                }
            }
            // Swap the two key values.
            swap(nums[i], nums[j]);
        }
            
        // Reverse the rest line.
        reverse(nums.begin() + i + 1, nums.end());
    }
};
