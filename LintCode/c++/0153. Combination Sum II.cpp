class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        dfs(num, 0, target);
        return result;
    }
    
    vector<vector<int>> result;
    vector<int> answer;
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
