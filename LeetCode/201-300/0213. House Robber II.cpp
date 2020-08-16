class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
    }
    
    int rob1(const vector<int>& nums, int begin, int end) {
        int robbed = 0;
        int skipped = 0;

        for (int i = begin; i < end; i++) {
            int previous_robbed = robbed;
            robbed = skipped + nums[i];
            skipped = max(skipped, previous_robbed);
        }
        return max(robbed, skipped);
    }
};
