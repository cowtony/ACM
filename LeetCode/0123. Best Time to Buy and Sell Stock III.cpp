class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, sold1 = 0, hold2 = INT_MIN, sold2 = 0;
        for (int price : prices) {
            hold1 = max(hold1, 0 - price);
            sold1 = max(sold1, hold1 + price);
            hold2 = max(hold2, sold1 - price);
            sold2 = max(sold2, hold2 + price);
        }
        return sold2;
    }
};
