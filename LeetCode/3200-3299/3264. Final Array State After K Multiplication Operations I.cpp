class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int min_idx = findMinimum(nums);
            nums[min_idx] *= multiplier;
        }
        return nums;
    }

    int findMinimum(const vector<int>& nums) {
        int minimum = INT_MAX, idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};
