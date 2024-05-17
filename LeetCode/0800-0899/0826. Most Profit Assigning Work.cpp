class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> diff_profit;
        for (int i = 0; i < difficulty.size(); i++) {
            diff_profit.push_back({difficulty[i], profit[i]});
        }
        sort(diff_profit.begin(), diff_profit.end());

        map<int, int> max_profit;
        int current_max_profit = 0;
        for (auto [diff, prof] : diff_profit) {
            current_max_profit = max(current_max_profit, prof);
            max_profit[diff] = current_max_profit;
        }

        int sum_profit = 0;
        for (int ability : worker) {
            auto it = max_profit.upper_bound(ability);
            if (it != max_profit.begin()) {
                it--;
                sum_profit += it->second;
            }
        }
        return sum_profit;
    }
};
