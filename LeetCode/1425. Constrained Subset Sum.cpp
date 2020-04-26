class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        deque<int> inc_deque;
        for (int i = 0; i < nums.size(); i++) {
            while (!inc_deque.empty() and inc_deque.front() < i - k) {
                inc_deque.pop_front();
            }
            
            dp[i] = nums[i];
            if (!inc_deque.empty()) {
                dp[i] = max(dp[i], dp[inc_deque.front()] + nums[i]);
            }
            
            while (!inc_deque.empty() and dp[inc_deque.back()] < dp[i]) {
                inc_deque.pop_back();
            }
            inc_deque.push_back(i);
        }
        
        int max_sum = INT_MIN;
        for (int sum : dp) {
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
    }
};
