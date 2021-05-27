class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) {
            return {};
        }
        dfs(s, 0, 0);
        return ans;
    }
    
    vector<string> ans;

    void dfs(string& s, int depth, int pos) {
        if (depth == 3) {
            if (s.length() - pos > 3) {
                return;
            }
            int num = stoi(s.substr(pos));
            if (num < 256 and to_string(num) == s.substr(pos)) {
                ans.emplace_back(s);
            }
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            int num = stoi(s.substr(pos, i));
            if (num < 256 and to_string(num) == s.substr(pos, i) and pos + i < s.length()) {
                s.insert(s.begin() + pos + i, '.');
                dfs(s, depth + 1, pos + i + 1);
                s.erase(s.begin() + pos + i);
            }
        }
    }
};
