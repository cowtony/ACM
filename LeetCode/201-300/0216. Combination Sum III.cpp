class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int start = 1) {
        if (k == 0 and n == 0) {
            return {{}};
        }

        vector<vector<int>> res;
        for (int i = start; i <= 9; i++) {
            for (const auto& v : combinationSum3(k - 1, n - i, i + 1)) {
                res.push_back({i});
                auto& temp = res.back();
                temp.insert(temp.end(), v.begin(), v.end());
            }
        }
        return res;
    }
};
