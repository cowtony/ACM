class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        vector<bool> visited(26, false);
        string result;  // Also act as a monostack
        for (char c : s) {
            if (visited[c - 'a']) {
                count[c - 'a']--;
                continue;
            }
            while (!result.empty() && count[result.back() - 'a'] > 1 && c < result.back()) {
                count[result.back() - 'a']--;
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c - 'a'] = true;
        }
        return result;
    }
};
