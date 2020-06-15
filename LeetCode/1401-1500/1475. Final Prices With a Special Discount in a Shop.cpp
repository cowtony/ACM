class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<size_t> mono_increase; 
        for (int i = 0; i < prices.size(); i++) {
            while (!mono_increase.empty() and prices[mono_increase.top()] >= prices[i]) {
                size_t idx = mono_increase.top();
                mono_increase.pop();
                prices[idx] -= prices[i];
            }
            mono_increase.push(i);
        }
        return prices;
    }
};
