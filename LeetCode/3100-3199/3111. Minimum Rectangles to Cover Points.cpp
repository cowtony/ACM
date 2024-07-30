class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        
        int x = -1000000001;
        int result = 0;
        for (const auto& point : points) {
            if (point[0] - x > w) {
                x = point[0];
                result++;
            }
        }
        return result;
    }
};
