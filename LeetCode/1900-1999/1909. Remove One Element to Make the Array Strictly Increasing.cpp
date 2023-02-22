class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        bool removed = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                if (i + 1 == nums.size() || 
                    i + 1 < nums.size() && nums[i - 1] < nums[i + 1]) {
                    // Remove nums[i]
                } else if (i - 2 >= 0 && nums[i] > nums[i - 2]) {
                    // Remove nums[i - 1]
                } else {
                    return false;
                }
                
                if (removed) {
                    return false;
                }
                removed = true;
            }
        }
        return true;
    }
};
