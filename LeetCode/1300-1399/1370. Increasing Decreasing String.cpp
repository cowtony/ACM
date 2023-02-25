class Solution {
public:
    string sortString(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string result;
        while (result.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    count[i]--;
                    result += i + 'a';
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (count[i] > 0) {
                    count[i]--;
                    result += i + 'a';
                }
            }
        }
        return result;
    }
};
