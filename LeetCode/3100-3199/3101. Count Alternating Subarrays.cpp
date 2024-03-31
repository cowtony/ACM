class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long result = 1;
        for (int l = 0, r = 1; r < nums.size(); r++) {
            if (nums[r] == nums[r - 1]) {
                l = r;
            }
            result += r - l + 1;
        }
        return result;
    }
};
