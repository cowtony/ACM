class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        vector<int> dp_cooldown(prices.size(), 0);
        vector<int> dp_sold(prices.size(), 0);
        vector<int> dp_hold(prices.size(), 0);
        dp_hold[0] = -prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            dp_cooldown[i] = max(dp_cooldown[i - 1], dp_sold[i - 1]);
            dp_hold[i] = max(dp_hold[i - 1], dp_cooldown[i - 1] - prices[i]);
            dp_sold[i] = dp_hold[i - 1] + prices[i];
        }
        
        return max(dp_cooldown.back(), dp_sold.back());
    }
};
