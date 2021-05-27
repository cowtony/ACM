class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        
        unordered_map<int, int> um; // Key = prefix_sum, Val = idx.
        int max_len = 0;
        for (int i = 0; i < prefix_sum.size(); i++) {
            if (um.find(prefix_sum[i] - k) != um.end()) {
                int len = i - um.at(prefix_sum[i] - k);
                max_len = max(max_len, len);
            } 
            if (um.find(prefix_sum[i]) == um.end()) {
                um[prefix_sum[i]] = i;
            }
        }
        
        return max_len;
    }
};
