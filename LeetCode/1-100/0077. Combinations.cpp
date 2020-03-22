class Solution {
public:
    vector<vector<int>> ret;
    
    vector<vector<int>> combine(int n, int k) {
        vector<bool> used(n + 1, false);
        
        vector<int> ans;
        dfs(n, k, used, ans);
        return ret;
    }
    
    void dfs(int n, int depth, vector<bool>& used, vector<int>& ans) {
        if (depth == 0) {
            ret.push_back(ans);
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                if (!ans.empty() && ans.back() >= i) {
                    continue;
                }
                used[i] = true;
                ans.push_back(i);
                dfs(n, depth - 1, used, ans);
                ans.pop_back();
                used[i] = false;
            }
        }
    }
};
