class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int minimum = INT_MAX, min_index = -1;
        int maximum = INT_MIN, max_index = -1;
        for (int l = 0, r = indexDifference; r < nums.size(); l++, r++) {
            if (nums[l] < minimum) {
                minimum = nums[l];
                min_index = l;
            }
            if (nums[l] > maximum) {
                maximum = nums[l];
                max_index = l;
            }
            if (abs(nums[r] - minimum) >= valueDifference) {
                return {min_index, r};
            }
            if (abs(nums[r] - maximum) >= valueDifference) {
                return {max_index, r};
            }
        }
        return {-1, -1};
    }
};
