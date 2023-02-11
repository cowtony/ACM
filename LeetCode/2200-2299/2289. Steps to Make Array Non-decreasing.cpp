class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int result = 0;
        vector<int> dp(nums.size(), 0);
        stack<int> monostack;  // mono decrease
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!monostack.empty() && nums[i] > nums[monostack.top()]) {
                dp[i]++;
                dp[i] = max(dp[i], dp[monostack.top()]);
                monostack.pop();
                result = max(result, dp[i]);
            }
            monostack.push(i);
        }
        return result;
    }
};
