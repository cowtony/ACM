class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        set<int> error;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                error.insert(i);
            }
        }
        
        vector<bool> result;
        for (const auto& query : queries) {
            auto it = error.lower_bound(query[0]);
            if (it == error.end()) {
                result.push_back(true);
            } else {
                int error_idx = *it;
                result.push_back(error_idx >= query[1]);
            }
        }
        return result;
    }
};
