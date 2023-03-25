class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sums;
        for (int i = 1; i < nums.size(); ++i) {
            if (sums.insert(nums[i] + nums[i - 1]).second == false) {
                return true;
            }
        }
        return false;
    }
};
