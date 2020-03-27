class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int max_length = 1;
        int inc_length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc_length++;
            } else {
                inc_length = 1;
            }
            max_length = max(max_length, inc_length);
        }
        return max_length;
    }
};
