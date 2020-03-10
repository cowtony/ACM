class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 or nums[i] >= nums.size()) {
                nums[i] = 0;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[nums[i] % nums.size()] += nums.size();
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums.size()) {
                return i;
            }
        }
        return nums.size();
    }
};
