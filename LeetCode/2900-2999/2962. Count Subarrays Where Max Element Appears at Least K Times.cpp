class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());

        vector<int> max_idx;
        max_idx.push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_val) {
                max_idx.push_back(i);
            }
        }

        long long result = 0;
        for (int i = 1; i + k - 1 < max_idx.size(); i++) {
            result += (long long)(max_idx[i] - max_idx[i - 1]) * (nums.size() - max_idx[i + k - 1]);
        }
        return result;
    }
};
