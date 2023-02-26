class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        return min(zigzag(nums, 0), zigzag(nums, 1));
    }

    int zigzag(const vector<int>& nums, int i) {
        int result = 0;
        for (; i < nums.size(); i += 2) {
            result += max(0, nums[i] - 
                             min(i > 0? nums[i - 1] : INT_MAX, 
                             i + 1 < nums.size()? nums[i + 1] : INT_MAX) + 1);
        }
        return result;
    }
};
