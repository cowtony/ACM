class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        for (int i = 0, j = 0, k = 0; k < nums.size(); ++k) {
            while (nums[j] < nums[k] - diff) {
                j++;
            }
            while (nums[i] < nums[j] - diff) {
                i++;
            }
            if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                count++;
            }
        }
        return count;
    }
};
