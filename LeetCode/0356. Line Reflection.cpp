struct hashFunc {
    size_t operator()(const vector<int>& point) const {
        return uint64_t(point[0]) << 32 | uint32_t(point[1]);
    }
};

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_set<vector<int>, hashFunc> dedup_points;
        int x_min = INT_MAX, x_max = INT_MIN;
        for (const auto& point : points) {
            dedup_points.insert(point);
            x_min = min(x_min, point[0]);
            x_max = max(x_max, point[0]);
        }
        
        for (vector<int> point : dedup_points) {
            point[0] = x_min + x_max - point[0];
            if (dedup_points.find(point) == dedup_points.end()) {
                return false;
            }
        }
        return true;
    }
};
