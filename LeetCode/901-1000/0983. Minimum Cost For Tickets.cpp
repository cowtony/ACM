class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        for (int day : days) {
            dp[day] = 1;
        }
        
        for (int i = 1; i < dp.size(); i++) {
            if (dp[i] == 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min({dp[i - 1] + costs[0], 
                             (i >= 7? dp[i - 7] : 0) + costs[1], 
                             (i >= 30? dp[i - 30] : 0) + costs[2]});
            }
        }
        
        return dp[365];
    }
};
