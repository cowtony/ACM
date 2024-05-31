class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<bool> seen(grid.size() * grid.size() + 1, false);
        int a;
        int b = (1 + grid.size() * grid.size()) * grid.size() * grid.size() / 2;
        for (auto row : grid) {
            for (auto num : row) {
                if (seen[num]) {
                    a = num;
                    b += num;
                }
                seen[num] = true;
                b -= num;
            }
        }
        return {a, b};
    }
};
