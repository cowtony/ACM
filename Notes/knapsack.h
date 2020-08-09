// 0-1 Knapsack
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
