class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int64_t result = 0;
        int bad_idx = -1, min_idx = -1, max_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                bad_idx = min_idx = max_idx = i;
            }
            if (nums[i] == minK) {
                min_idx = i;
            }
            if (nums[i] == maxK) {
                max_idx = i;
            }
            result += min(min_idx, max_idx) - bad_idx;
        }
        return result;
    }
};
