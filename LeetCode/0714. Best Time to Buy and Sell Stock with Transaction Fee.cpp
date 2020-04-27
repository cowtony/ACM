class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -100000, sold = 0;
        for (int price: prices) {
            hold = max(sold - price,       hold);
            sold = max(hold + price - fee, sold);
        }
        return sold;
    }
};
