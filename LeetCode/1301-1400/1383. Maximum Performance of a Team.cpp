bool Compare(int64_t a, int64_t b)
{
    return a > b;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // First sort by efficiency from small to large.
        vector<pair<int64_t, int64_t>> eff_sp;
        for (int i = 0; i < n; i++) {
            eff_sp.push_back({efficiency[i], speed[i]});
        }
        sort(eff_sp.begin(), eff_sp.end(), [](pair<int64_t, int64_t> a, pair<int64_t, int64_t> b){return a.first < b.first;});
        
        // Then DP from efficiency right to left.
        int64_t sum = 0;
        int64_t ret = 0;
        priority_queue<int64_t, vector<int64_t>, function<bool(int64_t, int64_t)>> speed_pq(Compare);
        for (int i = n - 1; i > n - k; i--) {
            speed_pq.push(eff_sp[i].second);
            sum += eff_sp[i].second;
            ret = max(ret, eff_sp[i].first * sum);
        }
        
        for (int i = n - k; i >= 0; i--) {
            ret = max(ret, eff_sp[i].first * (sum + eff_sp[i].second));
            speed_pq.push(eff_sp[i].second);
            sum += eff_sp[i].second - speed_pq.top();
            speed_pq.pop();
        }

        return ret % 1000000007;
    }
};
