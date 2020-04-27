class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        for (int i = 1; i < prices.size(); i++) {
            total += max(0, prices[i] - prices[i - 1]);
        }
        return total;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -100000, sold = 0;
        for (int price: prices) {
            if (sold - price > hold) hold = sold - price;
            if (hold + price > sold) sold = hold + price;  // Only one of these will be execute
            // hold = max(sold - price, hold);
            // sold = max(hold + price, sold);
        }
        return sold;
    }
}; // DP way


