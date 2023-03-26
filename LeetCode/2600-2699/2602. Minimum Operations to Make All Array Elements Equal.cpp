class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> prefix_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        
        vector<long long> result;
        result.reserve(queries.size());
        for (long long query : queries) {
            int smaller = lower_bound(nums.begin(), nums.end(), query) - nums.begin();
            result.push_back(prefix_sum.back() + 2 * query * smaller - 2 * prefix_sum[smaller] - query * nums.size());
        }
        return result;
    }
};
