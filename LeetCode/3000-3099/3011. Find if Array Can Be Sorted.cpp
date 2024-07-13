class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        set<int> numSet;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
            if (i + 1 == nums.size() || __builtin_popcount(nums[i]) != __builtin_popcount(nums[i + 1])) {
                if (*numSet.begin() < prev) {
                    return false;
                }
                prev = *numSet.rbegin();
                numSet.clear();
            }
        }
        return true;
    }
};
