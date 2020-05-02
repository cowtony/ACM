class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> um;
        for (int r = nums.size() - 1; r >= 0; r--) {
            for (int c = 0; c < nums[r].size(); c++) {
                um[r + c].push_back(nums[r][c]);
            }
        }

        map<int, vector<int>> its;
        for (auto p : um) {
            its[p.first] = p.second;
        }

        vector<int> ret;
        for (auto p : its) {
            ret.insert(ret.end(), p.second.begin(), p.second.end());
        }
        return ret;
    }
};
