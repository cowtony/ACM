class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 100, 0);
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            for (int j = 0, sum = 0; j < 3 and i + j < stoneValue.size(); j++) {
                sum += stoneValue[i + j];
                dp[i] = max(dp[i], sum - dp[i + 1 + j]);
            }
        }
        
        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
