class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> shifts(26, 0);
        for (int i = 0; i < s.length(); i++) {
            int tmp = (t[i] - s[i] + 26) % 26;
            if (s[i] != t[i] and shifts[tmp]++ * 26 + tmp > k) {
                return false;
            }
        }
        return true;
    }
};
