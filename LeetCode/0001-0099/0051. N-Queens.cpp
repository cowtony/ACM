class Solution {
public:
    vector<bool> column_used;
    vector<bool> left;
    vector<bool> right;
    vector<int> answer;
    vector<vector<string>> ret;
    
    vector<vector<string>> solveNQueens(int n) {
        column_used = vector<bool>(n, false);
        left = vector<bool>(2 * n - 1, false);
        right = vector<bool>(2 * n - 1, false);
        
        dfs(n, 0);
        return ret;
    }
    
    void dfs(int n, int row) {
        if (row == n) {
            ret.push_back(createAnswer(answer, n));
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!column_used[col] and !left[row - col + n] and !right[row + col]) {
            
                column_used[col] = true;
                left[row - col + n] = true;
                right[row + col] = true;
                answer.push_back(col);
                dfs(n, row + 1);
                answer.pop_back();
                column_used[col] = false;
                left[row - col + n] = false;
                right[row + col] = false;
            }
        }
    }
    
    vector<string> createAnswer(const vector<int>& answer, int n) {
        vector<string> ret;
        for (int col : answer) {
            string s(n, '.');
            s[col] = 'Q';
            ret.push_back(s);
        }
        return ret;
    }
};
