class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> net_profit;
        net_profit.reserve(profits.size());
        for (int i = 0; i < profits.size(); i++) {
            net_profit.push_back({capital[i], profits[i]});
        }
        sort(net_profit.begin(), net_profit.end());

        priority_queue<pair<int, int>> pq;
        int i = 0;
        while (true) {
            if (i < net_profit.size() && net_profit[i].first <= w) {
                pq.push({net_profit[i].second, net_profit[i].first});
                i++;
            } else if (k == 0 || pq.empty()) {
                return w;
            } else {
                k--;
                w += pq.top().first;
                pq.pop();
            }
        }
        return w;
    }
};
