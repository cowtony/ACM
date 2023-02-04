class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int count = 0;
        int limit = INT_MAX;
        for (const auto& point : points) {
            if (point[0] > limit) {
                count++;
                limit = INT_MAX;
            }
            limit = min(limit, point[1]);
        }
        return count + 1;
    }
};