class Solution {
public:
    vector<vector<int>> result;
    vector<int> answer;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, 0, target);
        return result;
    }
    
    void dfs(vector<int>& candidates, int index, int target) {
        if (target == 0) {
            result.emplace_back(answer);
            return;
        }
        for (int i = index; i < candidates.size() and candidates[i] <= target; i++) {
            answer.emplace_back(candidates[i]);
            dfs(candidates, i, target - candidates[i]);
            answer.pop_back();
        }
    }
};
