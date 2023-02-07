class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int64_t num = 0;
        int64_t max_num = 0, min_num = 0;
        for (int difference : differences) {
            num += difference;
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }

        return max(0L, (upper - lower) - (max_num - min_num) + 1);
    }
};