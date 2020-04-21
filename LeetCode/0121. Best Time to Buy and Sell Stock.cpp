class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (const int &price: prices)
        {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
        /*
        int sum = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            sum = max(0, sum + prices[i] - prices[i - 1]);
            maxProfit = max(maxProfit, sum);
        }
        return maxProfit;
        */
    }
};
