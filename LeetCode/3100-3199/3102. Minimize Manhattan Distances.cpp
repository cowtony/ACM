class Solution {
public:
    
    int minimumDistance(vector<vector<int>>& points) {
        auto [_, a, b] = getMaxManhattanDistance(points);
        return min(getMaxManhattanDistance(points, a)[0], getMaxManhattanDistance(points, b)[0]);
    }
    
    array<int, 3> getMaxManhattanDistance(vector<vector<int>>& points, int skip = -1) const {
        int min_sum = 1e9, min_sum_idx;
        int max_sum = -1e9, max_sum_idx;
        int min_diff = 1e9, min_diff_idx;
        int max_diff = -1e9, max_diff_idx;

        for (int i = 0; i < points.size(); i++) {
            if (i == skip) {
                continue;
            }

            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];
            if (sum < min_sum) {
                min_sum = sum;
                min_sum_idx = i;
            }
            if (sum > max_sum) {
                max_sum = sum;
                max_sum_idx = i;
            }
            if (diff < min_diff) {
                min_diff = diff;
                min_diff_idx = i;
            }
            if (diff > max_diff) {
                max_diff = diff;
                max_diff_idx = i;
            }
        }
        
        if (max_sum - min_sum > max_diff - min_diff) {
            return {max_sum - min_sum, max_sum_idx, min_sum_idx};
        } else {
            return {max_diff - min_diff, max_diff_idx, min_diff_idx};
        }
    }
    
};
