// 0-1 Knapsack
// Example: Divide the array into 2 so that their sum as close as possible.

int knapsack01(const vector<int>& weights, int capacity) {
	vector<bool> dp(capacity + 1, false);
    dp[0] = true;
    for(int weight : weights) {
        for(int i = capacity; i >= weight; i--) {
            dp[i] = dp[i] || dp[i - weight];
        }
    }
	for (int i = capacity; i >= weight[i]; i--) {
		if (dp[i]) {
			return i;
		}
	}
    return 0;
}

// When value is different than weight.
int knapsack01(const vector<int>& weight, const vector<int>& value, int capacity) {
    vector<int> dp(capacity + 1, 0);
    dp[0] = 0;
    for(int i = 0; i < weight.size(); i++) {
        for(int j = capacity; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[capacity];  // TODO: is it correct to return the dp[capacity]? or the largest value in dp[]?
}
// 2D problem: https://leetcode.com/problems/ones-and-zeroes/description/
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const string& s : strs) {
        int zero = count(s.begin(), s.end(), '0');
        int one = s.length() - zero;
        for (int i = m; i >= zero; i--) {
            for (int j = n; j >= one; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }
    return dp[m][n];
}

// TODO: When each item can be choose multiple times

