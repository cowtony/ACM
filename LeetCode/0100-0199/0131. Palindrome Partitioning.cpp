class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        if (is_palindrome[start][end] != -1) {
            return is_palindrome[start][end];
        }
        if (s[start] != s[end]) {
            return is_palindrome[start][end] = false;
        }
        if (start + 1 <= end - 1) {
            return isPalindrome(s, start + 1, end - 1);
        }
        return is_palindrome[start][end] = true;
    }

    vector<vector<string>> partition(string s) {
        is_palindrome = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        vector<string> path;
        dfs(s, 0, path);
        return result;
    }

    void dfs(const string& s, int start, vector<string>& path) {
        if (start >= s.length()) {
            result.emplace_back(path);
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.emplace_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, path);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> is_palindrome;
    vector<vector<string>> result;
};