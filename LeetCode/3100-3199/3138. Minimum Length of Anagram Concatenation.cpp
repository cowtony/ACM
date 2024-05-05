class Solution {
public:
    int minAnagramLength(string s) {
        vector<vector<int>> prefix_count(26, vector<int>(s.length() + 1, 0));
        for (int i = 0; i < s.length(); i++) {
            for (int c = 0; c < 26; c++) {
                prefix_count[c][i + 1] = prefix_count[c][i];
            }
            prefix_count[s[i] - 'a'][i + 1]++;
        }
        
        vector<int> sub_count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            sub_count[s[i] - 'a']++;
            if(possible(s, prefix_count, sub_count, i + 1)) {
                return i + 1;
            }
        }
        return s.length();  // This line will never be reached.
    }
    
    bool possible(const string& s, const vector<vector<int>>& prefix_count, const vector<int>& sub_count, int len) {
        if (s.length() % len != 0) {
            return false;
        }
        for (int i = len; i <= s.length(); i += len) {
            for (int c = 0; c < 26; c++) {
                int c_count = prefix_count[c][i] - prefix_count[c][i - len];
                if (c_count != sub_count[c]) {
                    return false;
                }
            }
        }
        return true;
    }
};
