class Solution {
public:
    vector<vector<int>> result;
    vector<int> answer;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            answer.emplace_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            answer.pop_back();
        }
    }
};
