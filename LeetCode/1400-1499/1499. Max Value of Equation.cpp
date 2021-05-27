class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        deque<pair<int, int>> mono_decrease; // Store the [index, val] of decrease Xj + Yj.
        for (int low = 0, high = 1; low < points.size() - 1; low++) {
            while (high < points.size() and points[high][0] - points[low][0] <= k) {
                int val = points[high][0] + points[high][1];
                while (!mono_decrease.empty() and mono_decrease.back().second <= val) {
                    mono_decrease.pop_back();
                }
                mono_decrease.push_back({high, val});
                high++;
            }
            
            if (!mono_decrease.empty() and mono_decrease.front().first <= low) {
                mono_decrease.pop_front();
            }
            if (!mono_decrease.empty()) {
                res = max(res, mono_decrease.front().second - points[low][0] + points[low][1]);
            }
        }
        return res;
    }
};
