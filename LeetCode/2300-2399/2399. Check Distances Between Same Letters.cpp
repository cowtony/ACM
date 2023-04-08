class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> idx(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            int char_idx = s[i] - 'a';
            if (idx[char_idx] == -1) {
                idx[char_idx] = i;
            } else if (i - idx[char_idx] - 1 != distance[char_idx]) {
                return false;
            }
        }
        return true;
    }
};
