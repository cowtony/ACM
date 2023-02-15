class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int64_t max_sum = 0;
        for (int& num : nums) {
            if (num < 0) {
                num = -num;  // Convert array to all positive.
            } else {
                max_sum += num;  // Get the sum of all positive nums.
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<int64_t, int>> pq;
        pq.push({max_sum, 0});
        while(--k) {
            auto [sum, i] = pq.top();
            pq.pop();
            if (i < nums.size()) {
                    pq.push({sum               - nums[i], i + 1});  // Either remove current smallest value.
                if (i > 0) {
                    pq.push({sum + nums[i - 1] - nums[i], i + 1});  // Or also add the left smaller value.
                }
            }
        }
        return pq.top().first;
    }
};
