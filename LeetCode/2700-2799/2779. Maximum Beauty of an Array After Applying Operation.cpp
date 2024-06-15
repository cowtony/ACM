class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > 2 * k) {
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
