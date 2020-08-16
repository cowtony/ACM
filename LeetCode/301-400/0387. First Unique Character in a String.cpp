class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            } else {
                m[s[i]] = -1; // Means found repeat.
            }
        }
        int min_idx = INT_MAX;
        for (auto p : m) {
            if (p.second != -1) {
                min_idx = min(min_idx, p.second);
            }
        }
        return min_idx == INT_MAX? -1 : min_idx;
    }
};
