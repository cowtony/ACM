class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        int previous_giant = -1, last_in_range = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                previous_giant = i;
            }
            if (nums[i] >= left) {
                last_in_range = i;
            }
            res += last_in_range - previous_giant;  // (i - previous_giant) - (i - last_in_range);
        }
        return res;
    }
};
