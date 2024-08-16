class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minimum = INT_MAX / 2, maximum = INT_MIN / 2;
        int max_distance = 0;

        for (const auto& array : arrays) {
            max_distance = max({max_distance, array.back() - minimum, maximum - array.front()});

            minimum = min(minimum, array.front());
            maximum = max(maximum, array.back());
        }

        return max_distance;
    }
};
