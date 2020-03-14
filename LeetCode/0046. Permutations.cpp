class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used = vector<bool>(nums.size(), false);
        vector<int> ans;
        dfs(nums, ans, used);
        return result;
    }
    
    void dfs(const vector<int>& nums, vector<int>& ans, vector<bool>& used) {
        if (ans.size() == nums.size()) {
            result.push_back(ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                ans.push_back(nums[i]);
                dfs(nums, ans, used);
                ans.pop_back();
                used[i] = false;
            }
        }
    }
};
