class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> nums_w_idx;
        nums_w_idx.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            nums_w_idx.push_back({nums[i], i});
        }
        sort(nums_w_idx.begin(), nums_w_idx.end());

        long long score = 0;
        vector<bool> visited(nums.size(), false);
        
        for (const auto& [num, idx] : nums_w_idx) {
            if (!visited[idx]) {
                score += num;
                visited[idx] = true;
                if (idx > 0) {
                    visited[idx - 1] = true;
                }
                if (idx + 1 < nums.size()) {
                    visited[idx + 1] = true;
                }
            }
        }
        return score;
    }
};
