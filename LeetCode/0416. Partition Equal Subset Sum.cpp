class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int num : nums) {
            target += num;
        }

        if (target % 2 == 1) {
            return false;
        }
        target /= 2;

        return knapsack01(nums, nums, target) == target;
    }
    
    int knapsack01(const vector<int>& weight, const vector<int>& value, int capacity) {
        vector<int> dp(capacity + 1, 0);
        dp[0] = 0;
        for(int i = 0; i < weight.size(); i++) {
            for(int j = capacity; j >= weight[i]; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        return dp[capacity];
    }
};
