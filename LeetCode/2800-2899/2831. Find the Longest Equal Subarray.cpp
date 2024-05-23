class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> count;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            count[nums[r]]++;

            while (r - l + 1 - count[nums[l]] > k) {
                count[nums[l]]--;
                l++;
            }
            result = max(result, count[nums[r]]);
        }
        return result;
    }
};
