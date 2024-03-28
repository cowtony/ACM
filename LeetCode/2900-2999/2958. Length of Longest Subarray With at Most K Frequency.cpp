class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        int result = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            count[nums[r]]++;
            while (count[nums[r]] > k && l < r) {
                count[nums[l++]]--;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
