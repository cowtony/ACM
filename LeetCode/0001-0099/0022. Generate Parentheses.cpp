class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(n, "", 0, result);
        return result;
    }
    
  private:
    void dfs(int total, string s, int open_left, vector<string>& result) {
        if (s.length() == total * 2) {
            if (open_left == 0) {
                result.push_back(s);
            }
            return;
        }
        if (open_left < total) {
            dfs(total, s + '(', open_left + 1, result);
        }
        if (open_left > 0) {
            dfs(total, s + ')', open_left - 1, result);
        }
    }
};
