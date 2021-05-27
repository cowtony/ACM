class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_length = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_length) {
                return false;
            }
            max_length = max(max_length, nums[i] + i);
        }
        return true;
    }
};
