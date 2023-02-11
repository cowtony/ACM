class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());  // By start time

        int result = INT_MIN, max_value = INT_MIN;
        map<int, int> dp;  // store the max event value after start time t
        for (int i = events.size() - 1; i >= 0; i--) {
            auto it = dp.upper_bound(events[i][1]);
            result = max(result, events[i][2] + (it == dp.end()? 0 : it->second));

            dp[events[i][0]] = max_value = max(max_value, events[i][2]);
        }
        return result;
    }
};
