class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        nums_ = nums;
        for (int sz = 0; sz <= nums.size(); sz++) {
            dfs(0, 0, sz);
        }
        return ans;
    }
private:
    vector<int> nums_;
    vector<vector<int>> ans;
    vector<int> result;
    
    void dfs(int depth, int current, int size) {
        if (depth == size) {
            ans.emplace_back(result);
            return;
        }
        int pre;
        bool has_pre = false;
        for (int i = current; i < nums_.size(); i++) {
            if (has_pre and nums_[i] == pre) {
                continue;
            }
            result.emplace_back(nums_[i]);
            dfs(depth + 1, i + 1, size);
            result.pop_back();
            pre = nums_[i];
            has_pre = true;
        }
    }
};
