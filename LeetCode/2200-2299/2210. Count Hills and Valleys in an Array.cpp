class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        int last_val = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[i + 1] && nums[i] > last_val || nums[i] < nums[i + 1] && nums[i] < last_val) {
                result++;
            }
            last_val = nums[i];
        }
        return result;
    }
};
